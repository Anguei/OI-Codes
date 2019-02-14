// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
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
#define fn "task"
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

int n, m, ans = 0;
const int N = 1000 + 5;
const int K = 2000;
int dp[N][5];
bool vis[N][5];
std::vector<int> g[N];

void clear() {
	ans = 0;
	rep(i, 0, N - 1) g[i].clear();
	memset(dp, 0, sizeof dp);
	memset(vis, 0, sizeof vis);
}

int dfs(int u, int state, int fa) {
	if (vis[u][state]) return dp[u][state];
	vis[u][state] = true;
	int &now = dp[u][state];
	
	now = K;
	for (const auto &v : g[u]) if (v ^ fa) now += dfs(v, 1, u);
	if (!state && fa ^ -1) ++now;
	if (state || fa == -1) {
		int sum = 0;
		for (const auto &v : g[u]) if (v ^ fa) sum += dfs(v, 0, u);
		if (fa != -1) ++sum;
		now = std::min(now, sum);
	}
	return now;
}

void input() {
	n = read(), m = read();
	rep(i, 1, m) {
		int u = read(), v = read();
		g[u].push_back(v); g[v].push_back(u);
	}
}

void compute() {
	rep(i, 1, n) if (!vis[i][0]) ans += dfs(i, 0, -1);
}

void output() {
	print(ans / K), pc('; ';), print(m - ans % K), pc('; ';), print(ans % K); puts("");
}

void solution() {
	clear();
	input();
	compute();
	output();
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else
#ifndef ONLINE_JUDGE
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    int T = read(); while (T--) solution();
}
