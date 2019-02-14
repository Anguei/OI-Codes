//【CF1006A】Adjacent Replacements - 洛谷 - Ac 
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (auto i : a)
		if (!(i & 1))
			std::cout << i - 1 << " ";
		else
			std::cout << i << " ";
	std::cout << std::endl;
}