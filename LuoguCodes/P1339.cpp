// luogu-judger-enable-o2
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 2500 + 5;
const int M = 6200 + 5;
int n, m, s, target;
int dis[N];
bool vis[N];

struct Edge
{
	int v, w;
	Edge() = default;
	Edge(int _v, int _w) : v(_v), w(_w) {}
	
	bool operator < (const Edge &rhs) const
	{
		return w > rhs.w;
	}
};
std::vector<Edge> g[M];

void init()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m >> s >> target;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
}

void dijkstra()
{
	std::priority_queue<Edge> pq;
	pq.push(Edge(s, 0));
	
	while (!pq.empty())
	{
		auto x = pq.top();
		pq.pop();
		int to = x.v; // 中转点 
		if (vis[to])
			continue;
		vis[to] = true;
		
		for (auto &e : g[to])
		{
			int to2 = e.v; // 该中转点可到达的点 
			if (dis[to2] > dis[to] + e.w)
			{
				dis[to2] = dis[to] + e.w; // 走中转点比直接去近 (e.w 是中转点到目标点距离） 
				pq.push(Edge(to2, dis[to2]));
			}
		}
	}
	
	std::cout << dis[target] << std::endl;
}

int main()
{
	init();
	dijkstra();
}