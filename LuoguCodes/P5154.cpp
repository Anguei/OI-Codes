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

const int N = 800 + 5;
int a[N], b[N], n, dp[N][N], sum[N], g[N][N];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void solution() {
	n = read(); rep(i, 1, n) a[i] = read(); rep(i, 1, n) b[i] = read(), sum[i] = sum[i - 1] + b[i];
	rep(i, 2, n) if (gcd(a[i], a[i - 1]) > 1) g[i - 1][i] = 1;
	rep(i, 1, n) if (g[i - 1][i] == 1) dp[i - 1][i] = b[i - 1] + b[i];
	per(i, n, 1) rep(j, i + 1, n) rep(k, i + 1, j - 1)
		if ((g[i][k] && g[k + 1][j]) || (g[i + 1][j - 1] && gcd(a[i], a[j]) > 1)) {
			g[i][j] = 1, dp[i][j] = sum[j] - sum[i - 1];
		}
	per(i, n, 1) rep(j, i + 1, n) rep(k, i, j) dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j]);
	println(dp[1][n]);
}

signed main() {
#ifdef yyfLocal
	fileIn;
	// fileOut;
#else  
#ifndef ONLINE_JUDGE   
	// freopen(fn".in", "r", stdin);
	// freopen(fn".out", "w", stdout);
#endif
#endif
	logs("main.exe");
	solution();
}