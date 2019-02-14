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
#define fn "1614"
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

const int N = 1000 + 5;
int n, m, k, l, r, maxW, dis[N];
bool done[N];// , inq[N];
std::vector<Edge> g[N];
std::priority_queue<Edge> pq;
// std::queue<Edge> q;

void clear() {
	memset(done, 0, sizeof done);
	memset(dis, 0x3f, sizeof dis);
	while (!pq.empty()) pq.pop();
	// memset(inq, 0, sizeof inq);
	// while (!q.empty()) q.pop();
}

bool check(int x) {
	clear();
	
	pq.push(Edge(1, 0)); dis[1] = 0;
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop(); int u = top.v;
		if (done[u]) continue; done[u] = true;
		for (const auto &e : g[u]) {
			int v = e.v, w = (e.w > x);
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(Edge(v, dis[v]));
			}
		}
	}
	
	/*q.push(Edge(1, 0)); dis[1] = 0; inq[1] = true;
	while (!q.empty()) {
		auto front = q.front(); q.pop(); int u = front.v; inq[u] = false;
		for (const auto &e : g[u]) {
			int v = e.v, w = (e.w > x);
			if (dis[v] > dis[u]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					q.push(Edge(v, dis[v]));
					inq[v] = true;
				}
			}
		}
	}*/
	
	return (dis[n] <= k);
}

void solution() {
	n = read(), m = read(), k = read();
	rep(i, 1, m) {
		int u = read(), v = read(), w = read();
		g[u].push_back(Edge(v, w));
		g[v].push_back(Edge(u, w));
		maxW = r = std::max(maxW, w);
	}
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	print(l == maxW ? -1 : l), puts("");
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
