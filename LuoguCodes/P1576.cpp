//【P1576】最小花费 - 洛谷 - Uk
#include <cstdio>
#include <queue>
#include <vector>
#include <iomanip>
#include <iostream> 
#include <algorithm>

struct Edge
{
	int to;
	double cost;
	Edge() = default;
	Edge(int _to, double _cost) : to(_to), cost(_cost) {}
	bool operator < (const Edge &rhs) const
	{
		return cost > rhs.cost;
	}
};

double dis[2005];
bool vis[2005];
std::vector<Edge> g[2005];

void dijkstra(int a, int b)
{
	std::priority_queue<Edge> pq;
	pq.push(Edge(a, 1));
	
	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		int to = top.to;
		if (vis[to])
			continue;
		vis[to] = true;
		
		for (auto &e : g[to])
		{
			int to2 = e.to;
			if (dis[to2] > dis[to] / e.cost)
			{
				dis[to2] = dis[to] / e.cost;
				pq.push(Edge(to2, dis[to2]));
			}
		}
	}
}

void spfa(int a, int b)
{
	std::queue<int> q;
	q.push(a);
	vis[a] = true;
	
	while (!q.empty())
	{
		auto front = q.front();
		q.pop();
		vis[front] = false;
		
		for (auto &e : g[front])
		{
			if (dis[e.to] > dis[front] / e.cost)
			{
				dis[e.to] = dis[front] / e.cost;
				if (!vis[e.to])
				{
					vis[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		double w;
		std::cin >> u >> v >> w;
		w /= 100;
		w = 1 - w;
		g[u].emplace_back(Edge(v, w));
		g[v].emplace_back(Edge(u, w));
	}
	int a, b;
	std::cin >> a >> b;
	std::fill(dis + 1, dis + n + 1, 0x7fffffff);
	dis[a] = 100;
	
	//dijkstra(a, b);
	spfa(a, b);
	
	//std::cout << std::setprecision(8) << dis[b] << std::endl;
	printf("%.8lf\n", dis[b]);
}