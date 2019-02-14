//【P1967】货车运输 - 洛谷 - Uk
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 100000 + 5;
const int M = 500000 + 5;

struct Edge
{
	int u, v, w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	Edge() {}
} e[M];

int n, m;
int fa[N], deep[N];
int f[N][25], w[N][25];
bool vis[N];
std::vector<Edge> g[N];

int find(int x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	fa[b] = a;
}

void kruscal()
{
	std::sort(e + 1, e + m + 1, [](const Edge &e1, const Edge &e2)
	{
		return e1.w > e2.w;
	});
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i)
		if (find(e[i].u) != find(e[i].v))
		{
			merge(e[i].u, e[i].v);
			g[e[i].u].emplace_back(Edge(e[i].u, e[i].v, e[i].w));
			g[e[i].v].emplace_back(Edge(e[i].v, e[i].u, e[i].w));
		}
}

void dfs(int now)
{
	vis[now] = true;
	for (auto &edge : g[now])
	{
		int to = edge.v;
		if (vis[to])
			continue;
		deep[to] = deep[now] + 1;
		f[to][0] = now;
		w[to][0] = edge.w;
		dfs(to);
	}
}

int lca(int x, int y)
{
	if (find(x) ^ find(y))
		return -1;
	int ans = 0x7fffffff;
	if (deep[x] > deep[y])
		std::swap(x, y);
	for (int i = 20; i >= 0; --i)
		if (deep[f[y][i]] >= deep[x])
		{
			ans = std::min(ans, w[y][i]);
			y = f[y][i];
		}
	if (x == y)
		return ans;
	for (int i = 20; i >= 0; --i)
		if (f[x][i] ^ f[y][i])
		{
			ans = std::min(ans, std::min(w[x][i], w[y][i]));
			x = f[x][i];
			y = f[y][i];
		}
	ans = std::min(ans, std::min(w[x][0], w[y][0]));
	return ans;
} 

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int _u, _v, _w;
		std::cin >> _u >> _v >> _w;
		e[i] = Edge(_u, _v, _w);
	}
	kruscal();
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			deep[i] = 1;
			dfs(i);
			f[i][0] = i;
			w[i][0] = 0x7fffffff;
		}
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j <= n; ++j)
		{
			f[j][i] = f[f[j][i - 1]][i - 1];
			w[j][i] = std::min(w[j][i - 1], w[f[j][i - 1]][i - 1]);
		}
	int q;
	std::cin >> q;
	while (q--)
	{
		int x, y;
		std::cin >> x >> y;
		std::cout << lca(x, y) << std::endl;
	}
}