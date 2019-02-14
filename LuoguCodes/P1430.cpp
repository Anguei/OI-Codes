// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 测试面包插件，提交 P1430
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
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define sum(l, r) (s[r] - s[l - 1])
#define pc(x) putchar(x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)
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
int a[N], s[N], dp[3][N][N];
/*
$ \text{DP}_{0, i, j} $ 表示在序列 $ [i, j] $ 范围内，A 能取到的最大值
$ \text{DP}_{1, i, j} $ 表示在 $ \text{DP}_{0, [i, j], j} $ 内的最小值
$ \text{DP}_{2, i, j} $ 表示在 $ \text{DP}_{0, i, [i, j]} $ 内的最小值
那么，$ \text{DP}_{0, i, j} $ 的最大值即为 $ \text{S}_{j, i - 1} - \min\left(\text{DP}_{1, i + 1, j}, \text{DP}_{2, i, j - 1}\right) $
综上，最终答案在 $ \text{DP}_{0, 1, n} $ 。
*/

int solve() {
    int n = read();
    rep(i, 1, n) s[i] = s[i - 1] + (dp[1][i][i] = dp[2][i][i] = dp[0][i][i] = a[i] = read());
    rep(len, 1, n) {
        rep(i, 1, n - len) {
            int j = i + len, min = 0;
            dp[0][i][j] = sum(i, j) - (min = std::min(min, std::min(dp[1][i + 1][j], dp[2][i][j - 1])));
            dp[1][i][j] = std::min(dp[1][i + 1][j], dp[0][i][j]);
            dp[2][i][j] = std::min(dp[2][i][j - 1], dp[0][i][j]);
        }
    }
    return dp[0][1][n];
}

signed main() {
    int T = read(); while (T--) print(solve()), puts("");
}