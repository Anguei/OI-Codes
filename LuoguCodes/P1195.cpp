//【P1195】口袋的天空 - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

const int kMaxN = 1000;
const int kMaxM = 10000;

struct Edge
{
	int u, v, w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	Edge() {}
};

Edge e[kMaxM + 5];
int fa[kMaxN + 5];

int find(int x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	fa[v] = u;
}

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		e[i] = Edge(u, v, w);
	}
	std::sort(e + 1, e + m + 1, [](const Edge &e1, const Edge &e2)
	{
		return e1.w < e2.w;
	});
	
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (find(e[i].u) != find(e[i].v))
		{
			ans += e[i].w;
			merge(e[i].u, e[i].v);
			if (++cnt == n - k)
			{
				std::cout << ans << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No Answer" << std::endl;
	
	return 0;
}