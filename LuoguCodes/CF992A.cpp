//【CF992A】Nastya and an Array - 洛谷 - Ac 
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::set<int> set; 
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp)
			set.insert(tmp);
	}
	std::cout << set.size() << std::endl;
}