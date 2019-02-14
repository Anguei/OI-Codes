#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize(3)
#define fn "guard"
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
	return res * flag;
}

void print(int x) {
	if (x < 0) x = -x, putchar(';-';);
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int N = 1500 + 5;
int n, dfsCnt = 0;
int dp[N][3], p[N], ind[N], outd[N];
std::vector<int> g[N];
std::queue<std::pair<int, int> > q;

void toposort() {
	rep(i, 1, n) if (!ind[i]) q.push(std::make_pair(i, 0));
	while (!q.empty()) {
		std::pair<int, int> x = q.front(); q.pop(); 
		int u = x.first; int fa = x.second;
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i]; 
			if (v != fa && !--ind[v])	q.push(std::make_pair(v, u));
		}
	}
}

void dfs(int u, int fa) {
	++dfsCnt;
	int sum = 0, min = 0x3f3f3f3f3f3f3f3f;
	dp[u][2] = p[u];
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		sum += std::min(dp[v][1], dp[v][2]);
		dp[u][2] += std::min(dp[v][0], std::min(dp[v][1], dp[v][2]));
	}
	dp[u][0] = sum; 
	dbg(sum);
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa) continue;
		min = std::min(min, sum - std::min(dp[v][1], dp[v][2]) + dp[v][2]);
	}
	dp[u][1] = min;
}

signed main() {
#ifdef yyfLocal
	freopen("testdata.in", "r", stdin);
#else
	#ifndef ONLINE_JUDGE
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
#endif
	n = read();
	rep(i, 1, n) {
		int u = read();
		int k = read(); p[u] = k;
		int m = read();
		rep(j, 1, m) {
			int v = read();
			g[u].push_back(v);
			g[v].push_back(u);
			++outd[u], ++ind[v];
			++outd[v], ++ind[u];
		}
	}
	//toposort();
	dfs(1, 0);
	print(std::min(dp[1][1], dp[1][2])), puts("");
	dbg(dfsCnt);
}