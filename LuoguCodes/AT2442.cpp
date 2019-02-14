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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i > (b); --i)
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

void solution() {
    int n = read(), q = read(), s = read(), t = read(), ans = 0;
    std::vector<int> a(n + 1), b(n + 1);
    rep(_, 0, n + 1) a[_] = read();
    rep(_, 0, n) b[_] = a[_ + 1] - a[_];
    rep(_, 0, n) ans += b[_] > 0 ? -b[_] * s : -b[_] * t;
    rep(_, 0, q) {
        int l = read(), r = read(), x = read(); l -= 1;
        ans -= b[l] > 0 ? -b[l] * s : -b[l] * t;
        b[l] += x;
        ans += b[l] > 0 ? -b[l] * s : -b[l] * t;
        if (r != n) {
            ans -= b[r] > 0 ? -b[r] * s : -b[r] * t;
            b[r] -= x;
            ans += b[r] > 0 ? -b[r] * s : -b[r] * t;
        }
        print(ans), puts("");
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
//     freopen(fn".in", "r", stdin);
//    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}
