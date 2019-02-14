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
#define fn "3887"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define dbg2(x, y) std::clog << #x " = " << (x) << ", " #y " = " << (y) << std::endl
#else
#define dbg(x) 42
#define dbg2(x, y) 42
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

const int N = 100000 + 5;
int n, m, dfsClock = 0, sccCnt = 0, low[N], dfn[N], color[N], size[N], dp[N][3], ind[N][3];
bool ins[N];
std::queue<int> q;
std::stack<int> stk;
std::vector<int> g[N], dag1[N], dag2[N];

void input() {
	n = read(), m = read();
	rep(i, 1, m) { // sillyBug: rep(i, 1, n)
		int u = read(), v = read();
		g[u].push_back(v);
	}
	memset(dp, 0xc0, sizeof dp);
}

void tarjan(int u) {
	low[u] = dfn[u] = ++dfsClock;
	stk.push(u); ins[u] = true;
	for (const auto &v : g[u]) {
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++sccCnt;
		do {
			color[u] = sccCnt;
			++size[sccCnt];
			u = stk.top(); stk.pop(); ins[u] = false;
		} while (low[u] != dfn[u]);
	}
}

void scc() {
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
}

void build() {
	rep(u, 1, n) for (const auto &v : g[u]) if (color[u] != color[v]) {
		dag1[color[u]].push_back(color[v]);
		dag2[color[v]].push_back(color[u]);
		++ind[color[v]][1];
		++ind[color[u]][2]; // sillyBug: ++ind[color[u]][1];
	}
}

void toposort1() {
	dp[color[1]][1] = size[color[1]];
	rep(i, 1, sccCnt) if (!ind[i][1]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (const auto &v : dag1[u]) {
			dp[v][1] = std::max(dp[v][1], dp[u][1] + size[v]);
			if (!--ind[v][1]) q.push(v);
		}
	}
}

void toposort2() {
	dp[color[1]][2] = size[color[1]];
	rep(i, 1, sccCnt) if (!ind[i][2]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (const auto &v : dag2[u]) { // sillyBug: for (const auto &v : dag1[u]) {
			dp[v][2] = std::max(dp[v][2], dp[u][2] + size[v]);
			if (!--ind[v][2]) q.push(v);
		}
	}
}

void compute() {
	int ans = size[color[1]]; // sillyBug: ans = size[1];
	rep(u, 1, n) for (const auto &v : g[u])
		if (color[u] != color[v])
			ans = std::max(ans, dp[color[v]][1] + dp[color[u]][2]);
	print(ans - size[color[1]]), puts("");
}

void solution() {
	input();
	scc();
	build();
	toposort1();
	toposort2();
	compute();
}

signed main() {
#ifdef yyfLocal
	fileIn;
#else
	#ifndef ONLINE_JUDGE
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
#endif
	solution();
}
