#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

long long dp[250005];

int main()
{
	int n, t;
	std::cin >> n >> t;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = a[i]; j <= t; ++j)
			dp[j] += dp[j - a[i]];
	std::cout << dp[t] << std::endl;
}