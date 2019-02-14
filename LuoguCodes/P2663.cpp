#include <iostream>
#include <algorithm>

int a[105];
int dp[10005];

int main()
{
	int n, sum = 0;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		sum += a[i];
	}
	sum /= 2;
	int ans = 0;
	for (int i = 1; i <= n; ++i)	
		for (int j = sum; j >= a[i]; --j)
		{
			int tmp = std::max(dp[j], dp[j - a[i]] + a[i]);
			if (tmp <= sum)
				ans = std::max(ans, dp[j] = tmp);
		}
	std::cout << ans << std::endl;
}