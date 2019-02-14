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
#define fn "1997"
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

const int N = 200 + 5, M = 10000 + 5;
int n, m, u, v, a[M], b[M], c[N], fa[M];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int solution() {
    n = read(), m = read();
    rep(i, 1, m) a[i] = read(), b[i] = read();
    rep(i, 1, n) c[read()] = i;
    if (m > 3 * n - 6) return puts("NO"), 0;
    rep(i, 1, m << 1) fa[i] = i;
    rep(i, 1, m - 1) rep(j, i + 1, m) if ((c[a[j]] - c[a[i]]) * (c[a[j]] - c[b[i]]) * (c[b[j]] - c[a[i]]) * (c[b[j]] - c[b[i]]) < 0) {
        u = find(i), v = find(j + m); if (u != v) fa[v] = u;
        u = find(i + m), v = find(j); if (u != v) fa[v] = u;
    }
    rep(i, 1, m) if (find(i) == find(i + m)) return puts("NO"), 0; return puts("YES"), 0;
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
    int T = read(); while (T--) solution();
}