#include <cstring>
#include <queue>
#include <vector> 
#include <iostream>
#include <algorithm>

const int N = 100 + 5;

struct Edge {
	int to, dis;
	Edge(int _to, int _dis) : to(_to), dis(_dis) {}
	Edge() = default;
	
	bool operator < (const Edge &rhs) const {
		return dis > rhs.dis;
	}
};

int n, a, b;
int dis[N];
bool done[N], inq[N];
std::vector<Edge> g[N];

void dijkstra() {
	memset(dis, 0x3f, sizeof dis);
	dis[a] = 0;
	std::priority_queue<Edge> pq;
	pq.push(Edge(a, 0));
	
	while (!pq.empty()) {
		auto to = pq.top().to; pq.pop();
		if (done[to]) continue;
		done[to] = true;
		for (auto &e : g[to]) {
			int to2 = e.to;
			if (dis[to2] > dis[to] + e.dis) {
				dis[to2] = dis[to] + e.dis;
				pq.push(Edge(to2, dis[to2]));
			}
		}
	}
	
	std::cout << (dis[b] == 0x3f3f3f3f ? -1 : dis[b]) << std::endl;
}

void spfa() {
	memset(dis, 0x3f, sizeof dis);
	dis[a] = 0;
	std::queue<int> q;
	q.push(a);
	
	while (!q.empty()) {
		auto to = q.front(); q.pop();
		inq[to] = false;
		for (auto &e : g[to]) {
			int to2 = e.to;
			if (dis[to2] > dis[to] + e.dis) {
				dis[to2] = dis[to] + e.dis;
				if (!inq[to2]) {
					inq[to2] = true;
					q.push(to2);
				}
			}
		}
	}
	
	std::cout << (dis[b] == 0x3f3f3f3f ? -1 : dis[b]) << std::endl;
}

int main() {
#ifdef yyfLocal
	freopen("d:\\Users\\yyf\\Downloads\\testdata (14).in", "r", stdin);
#endif
	std::cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; ++j) {
			int to;
			std::cin >> to;
			g[i].push_back(Edge(to, bool(j ^ 1)));
		}
	}
	dijkstra();
	//spfa();
}