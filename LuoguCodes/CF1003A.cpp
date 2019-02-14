//【CF1003A】Polycarps Pockets - 洛谷 - Ac 
#include <set>
#include <map>
#include <vector> 
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::map<int, int> m;
	int ans = 0;
	for (auto i : a)
		ans = std::max(ans, ++m[i]);
	std::cout << ans << std::endl;
}