//【CF999E】Reachability from the Capital - 洛谷 - Wa 
#include <cstring>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

int cnt = 0;
std::vector<int> g[5005];
bool vis1[5005], vis2[5005];

void dfs1(int now)
{
	vis1[now] = true;
	for (auto to : g[now])
		if (!vis1[to]) 
			dfs1(to);
}

void dfs2(int now)
{
	vis2[now] = true;
	++cnt;
	for (auto to : g[now])
		if (!vis2[to] && !vis1[to])
			dfs2(to);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, s;
	std::cin >> n >> m >> s;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		g[u].emplace_back(v);
	}
	
	dfs1(s);
	
	std::vector<std::pair<int, int>> val;
	for (int i = 1; i <= n; ++i)
		if (!vis1[i])
		{
			cnt = 0;
			memset(vis2, false, sizeof vis2);
			dfs2(i);
			val.emplace_back(std::make_pair(cnt, i));
		}
	std::sort(val.begin(), val.end(), std::greater<std::pair<int, int>>());
	
	int ans = 0;
	for (auto i : val)
		if (!vis1[i.second])
		{
			++ans;
			dfs1(i.second);
		} 
		
	std::cout << ans << std::endl;
}