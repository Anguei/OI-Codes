#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "task"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

struct Seg {
    int l, r, t;
    Seg() = default;
    Seg(int l, int r, int t) : l(l), r(r), t(t) {}
    bool operator < (const Seg &rhs) const {
        return t < rhs.t;
    }
};

const int N = 100000 + 5;
int n, L, a;
Seg s[N];

void solution() {
    n = read(), L = read(), a = read();
    rep(i, 1, n) s[i].l = read(), s[i].r = read(), s[i].t = s[i].l + s[i].r;
    s[n + 1] = Seg(L, 0, L);
    std::sort(s + 1, s + n + 2);
    int ans = 0;
    rep(i, 1, n + 1) ans += (s[i].l - s[i - 1].t) / a, dbg(s[i].l - s[i - 1].t);
    print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}
// Fark