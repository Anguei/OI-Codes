// luogu-judger-enable-o2
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue> 
#include <vector> 
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << x << std::endl
#else
#define dbg(x) x;
#endif

int read() {
	int res = 0, flag = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
	while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
	return res * flag;
}

struct Edge {
	int v, w;
	Edge() = default;
	Edge(int _v, int _w) : v(_v), w(_w) {}
};

const int N = 2000;

int n, m;
int dis[N], cnt[N];
bool inq[N];
std::vector<Edge> g[N];
std::queue<int> q;

bool spfa() {
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	memset(inq, false, sizeof inq);
	dis[1] = 0, cnt[1] = 0, inq[1] = true;
	q.push(1);
	while (!q.empty()) {
		auto to = q.front(); q.pop(); inq[to] = false;
		for (const auto &e : g[to]) {
			int to2 = e.v;
			if (dis[to2] > dis[to] + e.w) {
				dis[to2] = dis[to] + e.w;
				cnt[to2] = cnt[to] + 1;
				if (cnt[to2] >= n) return true;
				if (!inq[to2]) {
					inq[to2] = true;
					q.push(to2);
				}
			}
		}
	}
	return false;
}

int main() {
	int T = read();
	while (T--) {
		dbg(T);
		for (auto &i : g) i.clear(); 
		n = read(), m = read();
		rep(i, 1, m) {
			int u = read(), v = read(), w = read();
			g[u].push_back(Edge(v, w)); 
			if (w >= 0) g[v].push_back(Edge(u, w));
		}
		puts(spfa() ? "YE5" : "N0");
	}
}