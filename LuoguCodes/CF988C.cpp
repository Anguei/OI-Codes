//【CF988C】Equal Sums - 洛谷 - Ac 
#include <map>
#include <utility>
#include <iostream>

int a[static_cast<int>(2e5 + 5)];

std::map<int, std::pair<int, int>> map;

int main()
{
	int k; 
	std::cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		int n, sum = 0;
		std::cin >> n;
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> a[j];
			sum += a[j];
		}
		for (int j = 1; j <= n; ++j)
		{
			if (map.count(sum - a[j]))
			{
				std::cout << "YES\n" << i << " " << j  << std::endl << map[sum - a[j]].first << " " << map[sum - a[j]].second << std::endl;
				return 0;
			}
		}
		for (int j = 1; j <= n; ++j)
			map[sum - a[j]] = std::make_pair(i, j);
	}
	std::cout << "NO" << std::endl;
}