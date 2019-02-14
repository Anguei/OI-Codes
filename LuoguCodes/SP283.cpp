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

int hash(const std::string &s, int base) {
    int res = 0;
    for (int i = 0; i < 4; ++i) ((res *= base) += s[i]) %= 999999999;
    return res;
}

int isp(int x) {
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return i;
    return 1;
}

const int N = 3830 + 5;
int n, m, ans, a[N], dp[2][N][2];

void solution() {
    memset(a, 0, sizeof a); memset(dp, 0xcf, sizeof dp); ans = 0;
    n = read(); m = read(); rep(i, 1, n) a[i] = read(); dp[1][0][0] = dp[1][1][1] = 0;
    rep(i, 2, n) rep(j, 0, m) {
        dp[i & 1][j][0] = std::max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
        if (j >= 1) dp[i & 1][j][1] = std::max(dp[(i - 1) & 1][j - 1][0], dp[(i - 1) & 1][j - 1][1] + a[i]);
    }
    ans = std::max(dp[n & 1][m][1], dp[n & 1][m][0]); dbg(ans);
    memset(dp, 0xcf, sizeof dp); dp[1][1][1] = a[1];
    rep(i, 2, n) rep(j, 0, m) {
        dp[i & 1][j][0] = std::max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
        if (j >= 1) dp[i & 1][j][1] = std::max(dp[(i - 1) & 1][j - 1][0], dp[(i - 1) & 1][j - 1][1] + a[i]);
    }
    ans = std::max(ans, dp[n & 1][m][1]);
    println(ans);
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    int T = read(); while(T--) solution();
}