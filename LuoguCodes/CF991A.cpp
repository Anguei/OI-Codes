//【CF991A】If at first you dont succeed - 洛谷 - Ac
#include <iostream>
#include <algorithm>

int main()
{
	int a, b, c, n;
	std::cin >> a >> b >> c >> n;
	if (n == 0 || c > b || c > a || c > n)
	{
		std::cout << -1 << std::endl;
		return 0;
	}
	
	int passed = a + b - c;
	if (passed >= n)
	{
		std::cout << -1 << std::endl;
		return 0;
	}
	std::cout << n - passed << std::endl;
}