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
// #define int long long
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

const int N = 10000000 + 5;
int l, r, n, a[N], b[N];
bool v[N];

void init() {
    memset(v, true, sizeof v);
    rep(i, 2, 46341) if (v[i]) {
        a[++n] = i;
        rep(j, 2, 46341 / i) v[i * j] = false;
    }
}

void solution() {
    int m = 0, x = 0, xx = 0, y = 0, yy = 0;
    memset(v, true, sizeof v);
    if (l == 1) v[0] = false;
    rep(i, 1, n) rep(j, l / a[i], r / a[i]) if (a[i] * j - l < 0) continue; else if (j > 1) v[a[i] * j - l] = false;
    rep(i, l, r) { if (v[i - l]) b[++m] = i; if (i == r) break; }
    int min = -1u / 2, max = 0;
    rep(i, 1, m - 1) {
        int j = b[i + 1] - b[i];
        if (j < min) min = j, x = b[i], y = b[i + 1];
        if (j > max) max = j, xx = b[i], yy = b[i + 1];
    }
    if (max) printf("%d,%d are closest, %d,%d are most distant.\n", x, y, xx, yy);
    else puts("There are no adjacent primes.");
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
    init();
    while (std::cin >> l >> r) solution();
}