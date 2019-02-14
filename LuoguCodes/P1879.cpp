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
#define fn "1725"
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

const int N = 12 + 1, STATE = (1 << 12) + 1, mod = 100000000;
int n, m, ans = 0, maxState = 0, line[N], dp[N][STATE];
bool map[N][N], state[STATE];

void solution() {
    n = read(), m = read(); maxState = (1 << m); dp[0][0] = 1;
    rep(i, 1, n) rep(j, 1, m) line[i] <<= 1, line[i] |= (map[i][j] = read());
    rep(i, 0, maxState - 1) state[i] = ((i << 1 & i) == 0) & ((i >> 1 & i) == 0);
    rep(i, 1, n) rep(j, 0, maxState - 1) if (state[j] && ((line[i] & j) == j)) rep(k, 0, maxState - 1) if (!(k & j)) dp[i][j] = dp[i][j] += dp[i - 1][k], dp[i][j] %= mod;
    rep(i, 0, maxState - 1) ans += dp[n][i], ans %= mod; print(ans), puts("");
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