#include <cmath>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::ios::sync_with_stdio(false);
	while (std::cin >> n && n)
	{
		if (n > 0)
		{
			int a, b;
			for (int i = 31; i >= 0; --i)
			{
				a = floor(pow(n, 1.0 / i) + 0.5);
				b = floor(pow(a, i) + 0.5);
				if (n == b)
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
		else
		{
			n = -n;
			int a, b;
			for (int i = 31; i >= 0; i -= 2)
			{
				a = floor(pow(n, 1.0 / i) + 0.5);
				b = floor(pow(a, i) + 0.5);
				if (n == b)
				{
					std::cout << i << std::endl;
					break;
				}
			}
		}
	}
}