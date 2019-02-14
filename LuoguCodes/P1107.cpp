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

const int N = 2000 + 5, Ni = 5000 + 5;
int a[N][N], dp[N][N << 1],/* dp[i][j] 表示在第 i 棵树、高度为 j 时的最大收益 */ max[N]; // max[i] 表示第所有树在高度为 i 时的最大收益

signed main() {
    int n = read(), h = read(), delta = read();
    rep(i, 1, n) {
        int num = read();
        rep(j, 1, num) ++a[i][read()];
    }
    per(j, h, 1) rep(i, 1, n) {
        dp[i][j] = std::max(dp[i][j], dp[i][j + 1] + a[i][j]);
        if (h >= j + delta) dp[i][j] = std::max(dp[i][j], max[j + delta] + a[i][j]);
        max[j] = std::max(max[j], dp[i][j]);
    }
    print(max[1]), puts("");
}