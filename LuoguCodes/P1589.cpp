// luogu-judger-enable-o2
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
#define fn "cover"
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

struct Segment {
    int l, r;
    Segment() = default;
    Segment(int l, int r) : l(l), r(r) {}
};

const int N = 100000 + 5;
Segment seg[N];

void solution() {
    int n = read(), len = read();
    rep(i, 1, n) seg[i].l = read(), seg[i].r = read();
    std::sort(seg + 1, seg + n + 1, [](const Segment &s1, const Segment &s2) {
        return s1.l < s2.l;
    });
    int tot = 0, cur = 0;
    rep(i, 1, n) {
        cur = std::max(cur, seg[i].l);
        if (cur < seg[i].r) {
            int a = seg[i].r - cur;
            int b = a / len + static_cast<bool>(a % len);
            cur += b * len;
            tot += b;
        }
    }
    print(tot), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}