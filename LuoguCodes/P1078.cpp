//【P1078】文化之旅 - 洛谷 - Wa
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm> 

namespace Dijkstra_Wa_28pts
{
	const int kMaxN = 100; 
	int n, k, m, s, t;
	int c[kMaxN + 5], a[kMaxN + 5][kMaxN + 5];
	int dis[kMaxN + 5];
	bool vis[kMaxN + 5];
	
	struct Edge
	{
		int v, w;
		Edge (int _v, int _w) : v(_v), w(_w) {}
		Edge() = default;
		
		bool operator < (const Edge &rhs) const
		{
			return w > rhs.w;
		}
	}; 
	std::vector<Edge> g[kMaxN + 5];
	
	
	int read()
	{
		int res = 0;
		char ch = getchar();
		while (!isdigit(ch))
			ch = getchar();
		while (isdigit(ch))
		{
			res = res * 10 + ch - 48;
			ch = getchar();
		}
		return res;
	}
	
	
	void init()
	{
		n = read(), k = read(), m = read(), s = read(), t = read();
		for (int i = 1; i <= n; ++i)
			c[i] = read();
		if (c[s] == c[t])
			exit((puts("-1"), 0));
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				a[i][j] = read();
		for (int i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), w = read();
			g[u].emplace_back(Edge(v, w));
			g[v].emplace_back(Edge(u, w));
		}
		std::fill(dis + 1, dis + n + 1, 0x7fffffff);
		dis[s] = 0;
	}
	
	
	void dijkstra() 
	{
		std::priority_queue<Edge> pq;
		pq.push(Edge(s, 0));
		
		while (!pq.empty())
		{
			int to = pq.top().v;
			pq.pop();
			if (vis[to])
				continue;
			vis[to] = true;
			
			for (auto &e : g[to])
			{
				int to2 = e.v;
				if (dis[to2] > dis[to] + e.w)
				{
					if (c[to] ^ c[to2] && !a[to][to2])
						continue;
					dis[to2] = dis[to] + e.w;
					pq.push(Edge(to2, dis[to2]));
				}
			}
		}
		
		std::cout << (dis[t] == 0x7fffffff ? -1 : dis[t]) << std::endl;
	}
	
	
	int main()
	{
		init();
		dijkstra();
		return 0;
	}
};


namespace Floyd
{
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
	const int kMaxN = 100;
	int n, k, m, s, t;
	int dis[kMaxN + 5][kMaxN + 5];
	int a[kMaxN + 5][kMaxN + 5], c[kMaxN + 5];
	
	
	int read()
	{
		int res = 0;
		char ch = getchar();
		while (!isdigit(ch))
			ch = getchar();
		while (isdigit(ch))
		{
			res = res * 10 + ch - 48;
			ch = getchar();
		}
		return res;
	}
	
	
	void init()
	{
		n = read(), k = read(), m = read(), s = read(), t = read();
		for (int i = 1; i <= n; ++i)
			c[i] = read();
		if (c[s] == c[t])
			exit((puts("-1"), 0));
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				a[i][j] = read();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = (i ^ j ? 0x3f3f3f3f : 0);
		for (int i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), w = read();
			dis[u][v] = dis[v][u] = w;
		}
	}
	
	
	void floyd()
	{
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (i ^ k and k ^ j and c[i] ^ c[k] and c[k] ^ c[j] and !a[c[i]][c[k]] and !a[c[j]][c[k]])
						dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
		std::cout << (dis[s][t] ^ 0x3f3f3f3f ? dis[s][t] : -1) << std::endl;
	}
	
	
	int main() 
	{
		init();
		floyd();
		return 0;
	}
};

int main()
{
	Floyd::main();
}