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

struct Pos {
	int x, y;
	Pos() = default; Pos(int x, int y) : x(x), y(y) {}
};

struct Edge {
	int v; double w;
	Edge() = default; Edge(int v, double w) : v(v), w(w) {}
	bool operator < (const Edge &rhs) const { return w < rhs.w; }
};

const int N = 1000 + 5;
int n, w;
double m, dis[N];
bool done[N], inq[N];
Pos p[N];
std::vector<Edge> g[N];
std::queue<Edge> q;
std::priority_queue<Edge> pq;

int dijkstra(int s, int t) {
	std::fill(std::begin(dis), std::end(dis), 9999999); dis[s] = 0; pq.push(Edge(s, 0));
	while (!pq.empty()) {
		const auto top = pq.top(); pq.pop(); int u = top.v; if (done[u]) continue; done[u] = true;
		for (const auto &e : g[u]) { int v = e.v; double w = e.w;
			if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; pq.push(Edge(v, dis[v])); }
		}
	}
    dbg(dis[t]);
	return dis[t] != 9999999 ? static_cast<int>(dis[t] * 1000) : -1;
}

int spfa(int s, int t) {
    std::fill(std::begin(dis), std::end(dis), 9999999); dis[s] = 0; q.push(Edge(s, 0)); inq[s] = true;
    while (!q.empty()) {
        const auto front = q.front(); q.pop(); int u = front.v; inq[u] = false;
        for (const auto &e : g[u]) { int v = e.v; double w = e.w;
            if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; if (!inq[v]) { q.push(Edge(v, dis[v])); inq[v] = true; } }
        }
    }
    dbg(dis[t]);
	return dis[t] != 9999999 ? static_cast<int>(dis[t] * 1000) : -1;
}

void solution() {
#define sqr(x) ((x) * (x))
#define far(p1, p2) sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y))
#define add(x, y, z) g[(x)].push_back(Edge((y), (z)))
	n = read(), w = read(); std::cin >> m;
	rep(i, 1, n) p[i].x = read(), p[i].y = read();
	rep(i, 1, n) rep(j, i + 1, n) if (far(p[i], p[j]) <= m) { add(i, j, far(p[i], p[j])); add(j, i, far(p[i], p[j])); std::clog << i << " " << j << std::endl;}
	rep(i, 1, w) { int u = read(), v = read(); add(u, v, 0); add(v, u, 0); }
	// print(dijkstra(1, n)), puts("");
    print(spfa(1, n)), puts("");
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
    logs("main.exe");
    solution();
}