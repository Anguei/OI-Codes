// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "road"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#pragma GCC optimize(3)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << # x " = " << (x) << std::endl
#define logs(x) std::clog << x << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

#define ABS(x) ((x) > 0 ? (x) : -(x))

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
	Edge() {}
	Edge(int v, int w) : v(v), w(w) {}
};

const int N = 1000000 + 5;
int n, s, size[N], ind[N];
bool vis[N];
std::vector<Edge> g[N];

void cheat() {
	std::clog << "cheatment: "; puts("0");
	return;
}

void dfs(int u, int fa) {
	for (int i = 0; i < g[u].size(); ++i) {
		Edge e = g[u][i];
		if (e.v ^ fa) {
			dfs(e.v, u);
			size[u] += size[e.v];
		}
	}
}

int getSize(int u, int fa) {
	std::fill(size + 1, size + n + 1, 1);
	dfs(u, fa);
	return size[u];
}

namespace Baoli { // O(2n^2)
	void solution() {
		n = read();
		if (n == 2) {
			cheat();
#ifndef yyfLocal
			return;
#endif
		}
		rep(i, 2, n) {
			int u = read(), v = read(), w = read();
			g[u].push_back(Edge(v, w));
			g[v].push_back(Edge(u, w));
		}
		/*rep(i, 1, n) size[i] = 1;
		dfs(1, 1);
		rep(i, 1, n) dbg(size[i]);
		int ans = 0;
		rep(i, 1, n) for (int j = 0; j < g[i].size(); ++j) {
			int u = i, v = g[i][j].v, w = g[i][j].w;
			ans += abs(size[u] - size[v]) * w;
		}
		print(ans / 2);*/
		
		// std::clog << getSize(2, 5) << " " << getSize(5, 2) << std::endl;
		// exit(0);
		
		int ans = 0;
		rep(i, 1, n) for (int j = 0; j < g[i].size(); ++j) {
			dbg(i);
			int u = i, v = g[i][j].v, w = g[i][j].w;
			int sizeu = getSize(u, v); int sizev = getSize(v, u);
			std::clog << sizeu << " " << sizev << std::endl;
			ans += ABS(sizeu - sizev) * w;
		}
		print(ans / 2), puts("");
	}
}

namespace Zhengjie { // O(2n)
	void init_sons(int s) {
		rep(i, 1, n) size[i] = 1;
		dfs(s, s);
		//rep(i, 1, n) dbg(size[i]);
	}
	
	void solution() {
		n = read();
		if (n == 2) {
			cheat();
#ifndef yyfLocal
			return;
#endif
		}
		rep(i, 2, n) {
			int u = read(), v = read(), w = read();
			g[u].push_back(Edge(v, w));
			g[v].push_back(Edge(u, w));
			//std::clog << g[u][g[u].size() - 1].w << std::endl;
			++ind[u]; ++ind[v];
		}
		int start = 0;
		rep(i, 1, n) if (ind[i] == 1) {
			start = i;
			dbg(start);
			break;
		}
		
		init_sons(start);
		
		int ans = 0;
		rep(i, 1, n) for (int j = 0; j < g[i].size(); ++j) {
			int u = i, v = g[i][j].v, w = g[i][j].w;
			int tmp1 = size[u], tmp2 = size[v], sizeu, sizev;
			if (tmp1 < tmp2) sizeu = size[u], sizev = n - sizeu;
			else sizev = size[v], sizeu = n - sizev;
			//sizeu = size[u], sizev = n - sizeu;
			//if (!sizeu) ++sizeu, --sizev;
			//else if (!sizev) ++sizev, --sizeu;
			//if (!sizeu || !sizev) continue;
			// if (ind[u] == 1 || ind[v] == 1) sizeu = 1, sizev = n - sizeu;
//			std::clog << u << " " << v << " " << sizeu << " " << sizev << " " << w << " "<< abs(sizeu - sizev) * w << std::endl;
			ans += ABS(sizeu - sizev) * w;
		}
		dbg(ans);
		print(ans / 2), puts("");
		if (n == 20000) logs("126130795907978");
	} 
}

signed main() {
#ifdef yyfLocal
	fileIn;
	// fileOut;
#else
#ifndef ONLINE_JUDGE
	freopen(fn".in", "r", stdin);
	freopen(fn".out", "w", stdout);
#endif
#endif
	// Baoli::solution();
	Zhengjie::solution();
}

