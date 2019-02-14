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
#define ll long long
//#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (a); i >= (b); --i)
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

const int N = 55;
int n, kase = 0, T, t[N], m1, d[N], m2, e[N], dp[205][N];
bool hasTrain[205][N][2];

void clear() {
	memset(t, 0, sizeof t);
	memset(dp, 0, sizeof dp);
	memset(hasTrain, 0, sizeof hasTrain);
}

void solve() {
	clear();
	T = read();
	rep(i, 1, n - 1) t[i] = read();
	m1 = read(); rep(i, 1, m1) {
		d[i] = read();
		rep(j, 1, n - 1) {
			if (d[i] <= T) hasTrain[d[i]][j][0] = true;
			d[i] += t[j];
		}
	}
	m2 = read(); rep(i, 1, m2) {
		e[i] = read();
		per(j, n - 1, 1) {
			if (e[i] <= T) hasTrain[e[i]][j + 1][1] = true;
			e[i] += t[j];
		}
	}
	rep(i, 1, n - 1) dp[T][i] = 0x3f3f3f3f; dp[T][n] = 0;
	per(i, T - 1, 0) rep(j, 1, n) {
		dp[i][j] = dp[i + 1][j] + 1;
		if (j < n && hasTrain[i][j][0] && i + t[j] <= T) dp[i][j] = std::min(dp[i][j], dp[i + t[j]][j + 1]);
		if (j > 1 && hasTrain[i][j][1] && i + t[j - 1] <= T) dp[i][j] = std::min(dp[i][j], dp[i + t[j - 1]][j - 1]);
	}
	if (dp[0][1] >= 0x3f3f3f3f) puts("impossible");
	else print(dp[0][1]), puts("");
}

signed main() {
#ifdef yyfLocal
	fileIn;
	fileOut;
#endif
	while (std::cin >> n && n) printf("Case Number %d: ", ++kase), solve();
}