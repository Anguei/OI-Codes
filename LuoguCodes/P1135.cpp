//【P1135】奇怪的电梯 - 洛谷 - Uk 
#include <iostream>
#include <algorithm>

const int N = 200 + 5; 

int n, a, b;

int k[N];
bool vis[N];

int ans = 2147483647;

void dfs(int now, int depth)
{
	if (now == b)
	{
		ans = std::min(ans, depth);
		return;
	}
	if (depth >= ans)
		return;
	vis[now] = true;
	if (now + k[now] <= n and !vis[k[now] + now])
		dfs(k[now] + now, depth + 1);
	if (now - k[now] >= 1 and !vis[-k[now] + now])
		dfs(-k[now] + now, depth + 1);
	vis[now] = false;
}

int main()
{
	std::cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		std::cin >> k[i];
	dfs(a, 1);
	std::cout << (ans ^ 2147483647 ? ans - 1 : -1) << std::endl; 
}
