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
#define fn "4509"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
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

const int N = 50000 + 5;
int n, pos, a[N], dp[N][2];

void solution() {
    memset(dp, 0x3f, sizeof dp);
    n = read();
    rep(i, 1, n) a[i] = read() * 2;
    std::sort(a + 1, a + n + 1);

    dp[pos = 1][0] = 0;
    rep(i, 2, n) {
        while (pos + 1 < i && a[i] - a[pos + 1] > dp[pos + 1][0] + 2) ++pos;
        dp[i][0] = std::min(a[i] - a[pos], dp[pos + 1][0] + 2);
    }
    dp[pos = n][1] = 0;
    per(i, n - 1, 1) {
        while (pos - 1 > i && a[pos - 1] - a[i] > dp[pos - 1][1] + 2) --pos;
        dp[i][1] = std::min(a[pos] - a[i], dp[pos - 1][1] + 2);
    }
    int ans = -1ull / 2;
    int l = 1, r = n;
    while (l < r) {
        ans = std::min(ans, std::max((a[r] - a[l]) / 2, std::max(dp[l][0], dp[r][1]) + 2));
        if (dp[l + 1][0] < dp[r - 1][1]) ++l; else --r;
    }
    std::cout << std::fixed << std::setprecision(1) << static_cast<double>(ans) / 2 << std::endl;
}

signed main() {
#ifdef yyfLocal
	fileIn;
	//fileOut;
#else  
#ifndef ONLINE_JUDGE   
	freopen(fn".in", "r", stdin);
	freopen(fn".out", "w", stdout);
#endif
#endif
	solution();
}