//【P3371】【模板】单源最短路径 - 洛谷 - Ac 
#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

const int kMaxN = 10000;

int n, m, s;
int dis[kMaxN + 5]; // dis[i] 表示 s 到 i 的最短距离 
bool vis[kMaxN + 5];

class Edge
{
public:
	int v, w;

	Edge(int _v, int _w) : v(_v), w(_w) {}
	Edge() = default;

	bool operator < (const Edge &rhs) const
	{
		return w > rhs.w; // 距离小的先出队 
	}
};

std::vector<Edge> g[kMaxN + 5]; // g[u] 存储 u 出发的所有边，g[u].v, g[u].w 分别表示这条边到达的点和长度 

int read()
{
	int res = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == ';-';)
			flag = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		res = res * 10 + ch - 48;
		ch = getchar();
	}
	return res * flag;
}

void init()
{
	n = read(), m = read(), s = read();
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		u = read(), v = read(), w = read();
		g[u].emplace_back(Edge(v, w));
	}
	std::fill(dis + 1, dis + n + 1, 2147483647);
	dis[s] = 0;
}

void dijkstra()
{
	std::priority_queue<Edge> pq;
	pq.push(Edge(s, 0));

	while (!pq.empty())
	{
		int to = pq.top().v; // to 即为中转点
		pq.pop();
		if (vis[to])
			continue;
		vis[to] = true;

		for (auto &e : g[to])
		{
			int to2 = e.v;
			if (dis[to2] > dis[to] + e.w) // 若从中转点走过去更近
			{
				dis[to2] = dis[to] + e.w;
				pq.push(Edge(to2, dis[to2]));
			}
		}
	}
}

void print()
{
	for (int i = 1; i <= n; ++i)
		printf("%d ", dis[i]);
	puts("");
}

int main()
{
	init();
	dijkstra();
	print();
}