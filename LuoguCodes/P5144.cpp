// luogu-judger-enable-o2
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
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
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

const int N = 1000 + 5, M = 100 + 5;
int n, m, a[N], dp[N][M], xorSum[N];

void solution() {
    n = read(), m = read(); rep(i, 1, n) a[i] = read(), dp[i][1] = xorSum[i] = xorSum[i - 1] ^ a[i];
    // 设 dp[i][j] 表示前 i 节切成 j 段的最大值
    // rep(i, 1, n) dp[i][1] = xorSum[n];
    rep(i, 1, n) rep(j, 2, m) rep(k, 1, i) dp[i][j] = std::max(dp[i][j], dp[k][j - 1] + (xorSum[i] ^ xorSum[k]));
    println(dp[n][m]);
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