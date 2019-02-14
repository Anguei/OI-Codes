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
#define dbg(x) x
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

struct Edge {
	int v, w;
	Edge() = default;
	Edge(int _v, int _w) : v(_v), w(_w) {}
	bool operator < (const Edge &rhs) const {
		return w > rhs.w;
	}
};

const int N = 1500 + 5;
int dis[N];
bool inq[N];
std::queue<int> q;
std::vector<Edge> g[N];
std::priority_queue<Edge> pq;

void spfa() {
	std::fill(dis, dis + N, -1000000000);
	dis[1] = 0, inq[1] = true;
	q.push(1);
	while (!q.empty()) {
		int to = q.front(); q.pop(); inq[to] = false;
		for (const auto &e : g[to]) {
			int to2 = e.v;
			if (dis[to2] < dis[to] + e.w) {
				dis[to2] = dis[to] + e.w;
				inq[to2] = true;
				q.push(to2);
			}
		}
	}
}

int main() {
	int n = read(), m = read();
	while (m--) {
		int u = read(), v = read(), w = read();
		g[u].emplace_back(Edge(v, w));
	}
	spfa();
	print(dis[n] == -1000000000 ? -1 : dis[n]), puts("");
}