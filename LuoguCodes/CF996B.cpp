//【CF996B】World Cup - 洛谷 - Ac 
#include <cmath>
#include <iostream>
#include <algorithm>

int a[200005];

int main()
{
	int n;
	std::cin >> n;
	int ans = 0, min = 0x7fffffff;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		double tmp = ceil(std::max(a[i] - i, 0) / static_cast<double>(n));
		if (min > tmp)
		{
			min = tmp;
			ans = i + 1;
		}
	}
	std::cout << ans << std::endl;
}