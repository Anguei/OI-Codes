//【CF1005C】Summarize to the Power of Two - 洛谷 - Ac
#pragma GCC optimize(3)
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	if (n == 1)
	{
		std::cout << 1 << std::endl;
		return 0;
	}
	std::vector<int> a(n + 1);
	std::map<int, int> all;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		++all[a[i]];
	}
	std::vector<int> pows(30);
	for (int i = 0; i < 30; ++i)
		pows[i] = (1 << i);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		bool ok = false;
		for (int j = 0; j <= 30; ++j)
		{
			/*if (all.count(pows[j] - a[i]) && __builtin_popcount(pows[j] - a[i]) == 1)
			{
				ok = true;
				break;
			}*/
			if (all[(1 << j) - a[i]] && !((1 << j) == (a[i] << 1) && all[a[i]] == 1))
			{
				ok = true;
				break;
			}
		}
		if (!ok)
			++ans;
	}
	std::cout << ans << std::endl;
	/*int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		bool ok = false;
		for (int j = 1; j <= n; ++j) 
		{
			if (i == j)
				continue;
			if (__builtin_popcount(a[i] + a[j]) == 1)
			{
				ok = true;
				break;
			}
		}
		if (!ok)
			++ans;
	}
	std::cout << ans << std::endl;*/
}