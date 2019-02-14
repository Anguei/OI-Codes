//【CF988A】Diverse Team - 洛谷 - Ac 
#include <set> 
#include <utility>
#include <iostream>
#include <algorithm>

const int kMaxN = 100;

int a[kMaxN + 5];

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::set<int> set;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		set.insert(a[i]);
	}
	if (set.size() < k)
	{
		std::cout << "NO" << std::endl;
		return 0;
	}
	std::cout << "YES" << std::endl; 
	int cnt = 0;
	for (auto i : set)
	{
		if (++cnt <= k)
			std::cout << std::find(a + 1, a + n + 1, i) - a << " ";
	}
	std::cout << std::endl;
}