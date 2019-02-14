//【CF985A】Chess Placing - 洛谷 - Ac
#include <cmath>
#include <iostream>
#include <algorithm>

int p[105], board[105];

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n / 2; ++i)
	{
		std::cin >> p[i];
		board[p[i]] = true;
	}
	std::sort(p + 1, p + n / 2 + 1);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n / 2; ++i)
	{
		ans1 += std::abs(p[i] - 2 * i);
		ans2 += std::abs(p[i] - 2 * i + 1);
	}
	std::cout << (ans1 > ans2 ? ans2 : ans1) << std::endl;
}