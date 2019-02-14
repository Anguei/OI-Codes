#include <iostream>
#include <algorithm>

using ll = long long;

struct Data
{
	ll a, b;
} d[20005];
ll dp[20005];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	ll T;
	std::cin >> T;
	while (T--)
	{
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; ++i) 
			std::cin >> d[i].a >> d[i].b;
		std::sort(d + 1, d + n + 1, [](const Data &d1, const Data &d2)
		{
			return std::min(d1.a, d2.b) < std::min(d2.a, d1.b);
		});
		ll sum = 0;
		for (int i = 1; i <= n; ++i)
			dp[i] = std::max(dp[i - 1], (sum += d[i].a)) + d[i].b;
		std::cout << dp[n] << std::endl;
	}
}