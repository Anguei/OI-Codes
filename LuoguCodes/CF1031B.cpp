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

const int N = 200000 + 5;
int a[N], b[N], n, c[N];

void solution() {
    n = read();
    rep(i, 1, n - 1) a[i] = read();
    rep(i, 1, n - 1) b[i] = read();
    while (c[1] <= 3) {
        dbg(c[1]);
        bool flag = true;
        std::fill(c + 2, c + n + 1, 0);
        rep(i, 1, n - 1) rep(j, 1, 2) {
            int x = a[i] & j, y = b[i] & j;
            if (!x && y) { flag = 0; break; }
            if (x && !y) c[i + 1] += (c[i] & j) ? 0 : j;
            if (!x && !y) if (c[i] & j) { flag = 0; break; } else c[i + 1] += 0;
            if (x && y) if (c[i] & j) c[i + 1] += j; else { flag = 0; break; }
        }
        if (flag) {
            puts("YES");
            rep(i, 1, n) print(c[i]), pc('; ';); puts("");
            exit(0);
        }
        c[1] += 1;
    }
    puts("NO");
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
    logs("main.exe");
    solution();
}