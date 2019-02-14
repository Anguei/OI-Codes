#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cout << i % 2;
	std::cout << std::endl;
}