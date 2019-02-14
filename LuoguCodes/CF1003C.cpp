//【CF1003C】Intense Heat - 洛谷 - Ac
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	long double all = static_cast<long double>(s[n]) / n;
	long double max = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + k - 1; j <= n; ++j)
		{
			int part = (s[j] - s[i - 1]);
			max = std::max(max, static_cast<long double>(part) / (j - i + 1));
		}
	}
	std::cout << std::setprecision(15) << static_cast<long double>(max) << std::endl;
}