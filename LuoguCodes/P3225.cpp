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
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
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

const int N = 500 + 5;
int n, m, dfsClock = 0, normalNum = 0, cutNum = 0, ans, bns, group;
int low[N], dfn[N], color[N];
bool ins[N], isCut[N];
std::stack<int> stk;
std::vector<int> g[N];

void clear() {
	n = dfsClock = group = 0;
	ans = 0, bns = 1;
	memset(low, 0, sizeof low); 
	memset(dfn, 0, sizeof dfn); 
	memset(color, false, sizeof color);
	memset(isCut, false, sizeof isCut); 
	memset(ins, false, sizeof ins);
	while (!stk.empty()) stk.pop();
	for (int i = 0; i < N; ++i) g[i].clear();
}

void input() {
	rep(i, 1, m) {
		int u = read(), v = read();
		g[u].push_back(v); g[v].push_back(u);
		n = std::max(n, std::max(u, v));
	}
}

void tarjan(int u, int fa) {
	low[u] = dfn[u] = ++dfsClock;
	int child = 0;
	for (const auto &v : g[u]) {
		if (!dfn[v]) {
			tarjan(v, fa);
			low[u] = std::min(low[u], low[v]);
			if (u != fa && low[v] >= dfn[u]) isCut[u] = true;
			if (u == fa) ++child;
		} else {
			low[u] = std::min(low[u], dfn[v]); // silliBug: low[u] = std::min(low[u], dfn[u]);
		}
	}
	if (u == fa && child >= 2) isCut[u] = true;
}

void bcc() {
	rep(i, 1, n) if(!dfn[i]) tarjan(i, i);
}

void dfs(int u) {
	++normalNum;
	color[u] = group;
	for (const auto &v : g[u]) {
		if (isCut[v] && color[v] != group) {
			++cutNum;
			color[v] = group;
		}
		if (!color[v]) dfs(v);
	}
}

void compute() {
	rep(i, 1, n) {
		if (!color[i] && !isCut[i]) {
			++group;
			normalNum = cutNum = 0;
			dfs(i);
			if (cutNum == 0) {
				ans += 2;
				bns *= (normalNum - 1) * normalNum / 2;
			} else if (cutNum == 1) {
				ans += 1;
				bns *= normalNum;
			}
		}
	}
}

void output() {
	print(ans), pc('; ';), print(bns), puts("");
}

void solve() {
	clear();
	input();
	bcc();
	compute();
	output();
}

signed main() {
#ifdef yyfLocal
	fileIn;
#else
	#ifndef ONLINE_JUDGE
		freopen("2730.in", "r", stdin);
		freopen("2730.out", "w", stdout);
	#endif
#endif
	int kase = 0;
	while (std::cin >> m && m) {
		printf("Case "), print(++kase), printf(": ");
		solve();
	}
}