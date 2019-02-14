//【AT1483】1 - 洛谷 - Uke
#include <cmath>

#include <string>
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int point = n + 1;
	long long ans = 0;
	for (int i = 1; i < 10; ++i)
	{
		int n = point / static_cast<int>(std::pow(10, i));
		int m = point % static_cast<int>(std::pow(10, i));
		int k = std::pow(10, i - 1);
		ans += n * k;
		if (m > (k << 1))
			ans += k;
		else if (m > k)
			ans += m - k;
	}
	std::cout << ans << std::endl;
}