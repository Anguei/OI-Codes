// luogu-judger-enable-o2
//【P4306】[JSOI2010]连通数 - 洛谷 - Tle 
#include <cstring>
#include <vector>
#include <iostream>

const int kMaxN = 2000;

int n, ans = 0;

char map[kMaxN + 5][kMaxN + 5];
bool vis[kMaxN + 5];

std::vector<int> g[kMaxN + 5];

void dfs(int now)
{
	vis[now] = true;
	++ans; 
	for (auto to : g[now])
		if (!vis[to])
			dfs(to);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> map[i][j];
			if (map[i][j] - 48)
				g[i].emplace_back(j);
		}
	for (int i = 1; i <= n; ++i)
	{ 
		memset(vis, false, sizeof vis);
		dfs(i);
	} 
	std::cout << ans << std::endl;
}
