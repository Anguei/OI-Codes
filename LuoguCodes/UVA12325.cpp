#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define fn "diep-io"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, b, a) for (int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x " = " << (x) << std::endl
#else
#define dbg(x) 42
#endif

int read() {
	int res = 0, flag = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
	while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
	return flag * res;
}
void print(int x) {
	if (x < 0) x = -x, pc(';-';);
	if (x > 9) print(x / 10);
	pc(x % 10 + 48);
}

int n, ans, s[3], v[3];//, dp[1837323523];
double unit[3];

int solve() {
	n = read(), s[1] = read(), v[1] = read(), s[2] = read(), v[2] = read(); ans = 0;
	if (s[1] > s[2]) std::swap(s[1], s[2]), std::swap(v[1], v[2]);
	if (n / s[2] >= 65536) { rep(i, 0, s[1]) ans = std::max(ans, v[2] * i + (n - s[2] * i) / s[1] * v[1]); rep(i, 0, s[2]) ans = std::max(ans, v[1] * i + (n - s[1] * i) / s[2] * v[2]); }
	else rep(i, 0, n / s[2]) ans = std::max(ans, v[2] * i + (n - s[2] * i) / s[1] * v[1]);
	print(ans); puts("");
	return 0;
}

signed main() {
#ifdef yyfLocal
	freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);
#else
	#ifndef ONLINE_JUDGE
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
#endif
	// 感觉这个数据范围没法 dp 呀。。 
	int T = read(); 
	rep(t, 1, T) {
		printf("Case #"), print(t), printf(": ");
		solve();
	}
}
