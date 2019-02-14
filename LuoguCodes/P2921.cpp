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

const int N = 100000 + 5;
int n, sccCnt, dfsClock;
int low[N], dfn[N], color[N], size[N], ans[N], next[N];
std::vector<int> g[N];
std::stack<int> stk;
bool ins[N];

void tarjan(int u) {
	low[u] = dfn[u] = ++dfsClock;
	stk.push(u), ins[u] = true;
	for (const auto &v : g[u]) {
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
		else low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++sccCnt;
		do {
			++size[sccCnt];
			color[u] = sccCnt;
			u = stk.top(); stk.pop(); ins[u] = false;
		} while (low[u] != dfn[u]);
	}
}

void dfs(int fa, int u, int depth) {
	dbg(u);
	if (ans[u]) {
		ans[fa] = ans[u] + depth;
		return;
	}
	dfs(fa, next[u], depth + 1);
}

void solution() {
	n = read();
	rep(i, 1, n) {
		int u = i, v = read();
		next[u] = v;
		dbg(next[u]);
		g[u].push_back(v);
		ans[u] = u == v;
	}
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
	logs("tarjaned");
	rep(i, 1, n) if (size[color[i]] > 1) ans[i] = size[color[i]];
	rep(i, 1, n) if (!ans[i]) dfs(i, i, 0);
	logs("dfsed");
	rep(i, 1, n) print(ans[i]), puts("");
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
    solution();
}
