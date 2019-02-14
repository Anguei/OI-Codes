//【CF991B】Getting an A - 洛谷 - Ac 
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	double aver = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		aver += a[i];
	}
	aver /= n;
	std::sort(a.begin() + 1, a.end());
	int cnt = 0;
	for (int i = 1; i <= n && aver <= 4.5 - 0.000001; ++i)
	{
		aver += (5.0 - a[i]) / n;
		cnt = i;
	}
	std::cout << cnt << std::endl;
}