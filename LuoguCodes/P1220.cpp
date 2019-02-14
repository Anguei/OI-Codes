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
#define _ (0)
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, b, a) for (int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
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

const int N = 1000 + 5;
int n, c;
int a[N], s[N], dp[N][N][2];

signed main() {
#ifdef yyfLocal
    fileIn;
#endif
    n = read(), c = read();
    rep(i, 1, n) a[i] = read(), s[i] = s[i - 1] + read();
    memset(dp, 0x3f, sizeof dp); dp[c][c][0] = dp[c][c][1] = 0;
    per(i, c, 1) rep(j, i + 1, n) {
        dp[i][j][0] = std::min(dp[i][j][0], dp[i + 1][j][0] + (a[i + 1] - a[i]) * (s[n] - (s[j] - s[i])));
        dp[i][j][0] = std::min(dp[i][j][0], dp[i + 1][j][1] + (a[j] - a[i]) * (s[n] - (s[j] - s[i])));
        dp[i][j][1] = std::min(dp[i][j][1], dp[i][j - 1][0] + (a[j] - a[i]) * (s[n] - (s[j - 1] - s[i - 1])));
        dp[i][j][1] = std::min(dp[i][j][1], dp[i][j - 1][1] + (a[j] - a[j - 1]) * (s[n] - (s[j - 1] - s[i - 1])));
    }
    return print(std::min(dp[1][n][0], dp[1][n][1])), puts(""), ~~(0^_^0);
}