//【CF1006E】Military Problem - 洛谷 - Ac
#pragma GCC optimize(3)
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 200000 + 5;

struct Edge
{
	int to;
	Edge() = default;
	Edge(int _to) : to(_to) {}
};

int n, q, time = 0;
int fa[N], pOrder[N], id[N], size[N];
bool vis[N];
std::vector<Edge> g[N];

void dfs(int now)
{
	pOrder[now] = ++time;
	id[time] = now;
	size[now] = 1;
	for (auto &e : g[now])
	{ 
		int to = e.to;
		if (!vis[to])
		{
			vis[to] = true;
			dfs(to);
			size[now] += size[to];
		}
	}
}

int main()
{
#ifdef yyfLocal
	freopen("testdata.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> n >> q;
	fa[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		std::cin >> fa[i];
		g[fa[i]].emplace_back(Edge(i));
	}

	dfs(1);

	while (q--)
	{
		int u, k;
		std::cin >> u >> k;
		if (k <= size[u])
			std::cout << id[pOrder[u] + k - 1] << std::endl;
		else
			std::cout << -1 << std::endl;
	}
}