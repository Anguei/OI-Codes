#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	if (n == 1)
	{
		std::cout << -1 << std::endl;
		return 0;
	}
	std::vector<std::pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		std::cin >> tmp;
		a[i] = std::make_pair(tmp, i);
	}
	if (n == 2 && a[1].first == a[2].first)
	{
		std::cout << -1 << std::endl;
		return 0;
	}
	std::sort(a.begin() + 1, a.end());
	int tot = 0;
	for (auto i : a)
		tot += i.first;
	if (a[1].first != tot - a[1].first)
	{
		std::cout << 1 << std::endl << a[1].second << std::endl;
	}
	else
		std::cout << -1 << std::endl;
}