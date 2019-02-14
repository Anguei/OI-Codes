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
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
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

const int N = 10000 + 5;
int n, m, ans = 0, dfsClock = 0, sccCnt = 0;
int dfn[N], low[N], color[N], // 时间戳、追溯到的最早祖先、所属 scc 编号 
	a[N], dagA[N], // 原权值、所点后权值 
	ind[N], dis[N]; // 每个缩后点的入度、距离 
bool ins[N], inq[N]; // is_in_stack、is_in_queue 
std::queue<int> q; // 用来跑拓扑（最长路 spfa） 
std::stack<int> stk; // 用于保存当前 scc 中所有节点的栈 
std::vector<int> g[N], dag[N]; // 一个原图，一个缩点之后的有向无环图 

void tarjan(int u) {
	stk.push(u); ins[u] = true;
	dfn[u] = low[u] = ++dfsClock;
	for (auto v : g[u]) {
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); // 如果还没遍历，就 Tarjan 一下，然后更新最早能追溯到的祖先 
		else if (ins[v]) low[u] = std::min(low[u],dfn[v]); // 再更新 
	}
	if (low[u] == dfn[u]) { // 找到 scc 了，把整个 scc 内的点都染上颜色（缩点） 
		++sccCnt; // 计数器更新 
		do {
			color[u] = sccCnt; // 染色 
			dagA[sccCnt] += a[u]; // 缩点之后的权值要加起来 
			u = stk.top(); stk.pop(); ins[u] = false;
		} while (dfn[u] ^ low[u]);
	}
}

int spfa() {
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (auto v : dag[u])
			if (dis[u] + dagA[v] > dis[v]) {
				dis[v] = dis[u] + dagA[v];
				if (!inq[v]) q.push(v), inq[v] = true;
			}
	}
	int ans = -0x7fffffff;
	rep(i, 1, sccCnt) ans = std::max(ans, dis[i]);
	return ans;
}

signed main() {
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) {
		int u = read(), v = read();
		if (u ^ v) g[u].push_back(v);
	}
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
	rep(i, 1, n) for (auto v : g[i]) 
		if (color[i] ^ color[v]) { // 不是一个 scc 
			dag[color[i]].push_back(color[v]); // 给 scc 连边啦 
			++ind[color[v]]; // 更新 scc 的入度 
		}
	std::fill(dis, dis + N, -0x3f3f3f3f); // 初始化为负 
	rep(i, 1, sccCnt)
		if (!ind[i]) { // 入度为零的跑一遍才有意义 
			dis[i] = dagA[i]; // 距离先搞好 
			q.push(i); inq[i] = true;
		}
	print(spfa()), puts("");
}

















































/*#include <cmath>
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

const int N = 10000 + 5, M = 100000 + 5;
int n, m, dfsClock = 0, sccCnt = 0, ans = 0;
int price[N], price2[N], dfn[N], low[N], sccId[N], dis[N], ind[N];
int from[M], to[M];
bool ins[N];
std::stack<int> stk; 
std::queue<int> q;
std::vector<int> g[N];

void tarjan(int u) {
	dfn[u] = low[u] = ++dfsClock;
	stk.push(u); ins[u] = true;
	for (auto &v : g[u])
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
		//else if (!sccId[v]) low[u] = std::min(low[u], dfn[v]);
		else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
	if (low[u] == dfn[u]) {
		/*dbg(u);
		++sccCnt;
		vis[u] = false;
		while (1) {
			int x = stk.top(); stk.pop();
			sccId[x] = sccCnt;
			if (x == u) break;
			price[u] += price[x];
		}*\/
		++sccCnt;
		do {
			sccId[u] = sccCnt;
			price2[sccCnt] += price[u];
			u = stk.top(); stk.pop();
			ins[u] = false;
		} while (dfn[u] ^ low[u]);
	}
}

/*int topo() {
	rep(i, 1, n) if (!ind[i] && i == sccId[i]) q.push(i), dis[i] = price[i], dbg(price[i]);
	//rep(i, 1, n) dbg(dis[i]);
	while (!q.empty()) { // silliBug: while (q.empty()) { 
		int u = q.front(); q.pop(); 
		//dbg(u);
		for (auto &v : g[u]) {
			dbg("haha");
			dis[v] = std::max(dis[v], dis[u] + price[v]);
			--ind[v];
			if (!ind[v]) q.push(v);
		}
	}
	int max = 0;
	rep(i, 1, n) max = std::max(max, dis[i]);//, dbg(dis[i]);
	return max;
}*/

/*void spfa(int u) {
	memset(dis, 0, sizeof dis);
	memset(inq, false, sizeof inq);
}*\/

signed main() {
	n = read(), m = read();
	rep(i, 1, n) price[i] = read(); 
	rep(i, 1, m) g[from[i] = read()].push_back(to[i] = read());
	rep(i, 1, n) if (!dfn[i]) /*dbg(i),*\/ tarjan(i); // find scc
	for (auto &i : g) i.clear();
	rep(i, 1, m) if (sccId[from[i]] ^ sccId[to[i]]) g[sccId[from[i]]].push_back(sccId[to[i]]), ++ind[sccId[to[i]]]; // 如果不在一个 scc 里面就连起来两个 scc，顺便更新入度 
	//rep(i, 1, sccCnt) spfa(i);
	//print(ans), puts("");
	//print(topo()), puts("");
}*/