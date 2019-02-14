//【CF979A】Pizza, Pizza, Pizza!!! - 洛谷 - Ac 
#include <cmath>
#include <iostream>

int main()
{
	long long n;
	std::cin >> n;
	long long ans;
	if (n == 0)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	else
	{
		n += 1;
		std::cout << (n & 1 ? n : n / 2) << std::endl;
	}
	return 0;
	n += 1;
	double angle = static_cast<double>(360) / n;
	
}