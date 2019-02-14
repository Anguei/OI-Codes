// luogu-judger-enable-o2
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
//#define int long long
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

struct Edge {
	int v, w;
	Edge() = default;
	Edge(int v, int w) : v(v), w(w) {}
	
	bool operator < (const Edge &rhs) const {
		return w > rhs.w;
	}
};

const int N = 200000 + 5;
int n, m, sccCnt = 0, dfsClock = 0;
int low[N], dfn[N], size[N], color[N], dis[N];
bool ins[N], done[N], inq[N];
std::stack<int> stk;
std::vector<Edge> g[N], dag[N];
std::priority_queue<Edge> pq;
std::queue<int> q;

void tarjan(int u) {
	low[u] = dfn[u] = ++dfsClock;
	stk.push(u); ins[u] = true;
	for (const auto &e : g[u]) {
		const auto &v = e.v;
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++sccCnt;
		do {
			color[u] = sccCnt;
			++size[sccCnt];
			u = stk.top(); stk.pop(); ins[u] = false;
		} while(low[u] != dfn[u]);
	}
}

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0; pq.push(Edge(s, 0));// done[s] = true;
	while (!pq.empty()) {
		const auto x = pq.top(); pq.pop(); 
		if (done[x.v]) continue; done[x.v] = true;
		for (const auto &e : dag[x.v]) {
			const auto &v = e.v;
			if (dis[v] > dis[x.v] + e.w) {
				dis[v] = dis[x.v] + e.w;
				pq.push(Edge(v, dis[v]));
			}
		}
	}
}

void spfa(int s) {
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0; q.push(s); inq[s] = true;
	while (!q.empty()) {
		const auto x = q.front(); q.pop(); inq[x] = false;
		for (const auto &e : dag[x]) {
			if (dis[e.v] > dis[x] + e.w) {
				dis[e.v] = dis[x] + e.w;
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}
		}
	}
}

void solution() {
	n = read(), m = read();
	while (m--) {
		int u = read(), v = read(), w = read();
		g[u].push_back(Edge(v, w));
	}
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
	rep(u, 1, n) for (const auto &e : g[u]) {
		const auto &v = e.v;
		if (color[u] != color[v]) dag[color[u]].push_back(Edge(color[v], e.w));
	}
	dijkstra(color[1]);
	//spfa(color[1]);
	print(dis[color[n]]), puts("");
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
