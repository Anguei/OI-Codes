#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm> 
#define dbg(x) std::cout << #x << " = " << x << std::endl;

int read()
{
	int res = 0;
	char ch = std::cin.get();
	while (!isdigit(ch))
		ch = std::cin.get();
	while (isdigit(ch))
	{
		res = res * 10 + ch - 48;
		ch = std::cin.get();
	}
	return res;
}

struct Edge
{
	int to;
	Edge() = default;
	Edge(int _to) : to(_to) {}
};

int fa[400005], input[400005];
bool broken[400005];
std::vector<Edge> g[400005];

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

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n = read(), m = read();
	for (int i = 0; i < n; ++i)
		fa[i] = i;
	for (int i = 0; i < m; ++i)
	{
		int u = read(), v = read();
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int k = read();
	std::vector<int> ans(k + 1);
	for (int i = 0; i < k; ++i)
		broken[(input[i] = read())] = true;
	int tot = n - k;
	for (int i = 0; i < n; ++i)
		for (auto &e : g[i])
			if (!broken[i] && !broken[e.to] && (find(i) != find(e.to)))
			{
				merge(i, e.to);
				--tot; // 连通块个数减一
			}
	ans[k] = tot;
	// 逆序，把题目当中的「损毁」改为「修复」 
	for (int i = k - 1; i >= 0; --i)
	{
		++tot; // 起初是损毁状态，连通块个数增加 
		broken[input[i]] = false; // 修好了 
		for (auto &e : g[input[i]])
			if (!broken[e.to] && (find(input[i]) != find(e.to))) // 如果另一个星球未损毁且未连通 
			{
				merge(input[i], e.to);
				--tot; // 修好了，减一 
			}
		ans[i] = tot;
	}
	for (int i = 0; i <= k; ++i)
		std::cout << ans[i] << std::endl;
}