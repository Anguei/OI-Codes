//¡¾P3353¡¿ÔÚÄã´°ÍâÉÁÒ«µÄÐÇÐÇ - Âå¹È - Wa
#include <iostream>
#include <algorithm>

const int kMaxN = 100000;

bool vis[kMaxN + 5];

struct Star
{
	int x, b, sum;
} star[kMaxN + 5];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, w;
	std::cin >> n >> w;
	for (int i = 1; i <= n; ++i)
	{
		int x, b;
		std::cin >> x >> b;
		if (!vis[x])
		{
			vis[x] = true;
			star[x].b = b;
		}
		else
		{
			star[x].b += b;
		}
	}
	for (int i = 1; i <= n; ++i)
		star[i].sum = star[i - 1].sum + star[i].b;
	int max = -0x7fffffff;
	for (int i = 1; i <= n - w + 1; ++i)
		max = std::max(max, star[i + w - 1].sum - star[i - 1].sum);
	std::cout << max << std::endl;
}