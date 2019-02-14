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

struct Edge {
	int v, w;
	Edge() = default;
	Edge(int v, int w) : v(v), w(w) {}
	bool operator < (const Edge &rhs) const {
		return w > rhs.w;
	}
};

const int N = 50000 + 5;
int n, m, b;
int r[N], s[N], l[N], p[N], q[N], dis[N];
bool done[N];
std::vector<Edge> g[N];
std::priority_queue<Edge> pq;

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis); dis[s] = 0;
	pq.push(Edge(s, 0));
	while (!pq.empty()) {
		const auto x = pq.top(); pq.pop(); const auto u = x.v;
		if (done[u]) continue; done[u] = true;
		for (const auto &e : g[u]) {
			const auto &v = e.v, &w = e.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(Edge(v, dis[v]));
			}
		}
	}
}

void solution() {
	n = read(), m = read(), b = read();
	std::clog << n << " " << m << " " << b << std::endl;
	rep(i, 1, m) {
		r[i] = read(), s[i] = read(), l[i] = read();
		g[r[i]].push_back(Edge(s[i], l[i]));
		g[s[i]].push_back(Edge(r[i], l[i]));
	}
	
	dijkstra(1);
	
	rep(i, 1, b) {
		p[i] = read(), q[i] = read();
		print(dis[p[i]] + dis[q[i]]), puts("");
	}
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
