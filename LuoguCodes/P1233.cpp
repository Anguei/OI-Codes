#include <iostream>
#include <algorithm>

std::pair<int, int> a[5005];
int dp[5005];

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; ++i)
		dp[i] = 1;
	std::sort(a + 1, a + n + 1, std::greater<std::pair<int, int>>());
	int ans = 1;
	dp[1] = a[1].second;
	for (int i = 2; i <= n; ++i)
		if (a[i].second > dp[ans])
			dp[++ans] = a[i].second;
		else
			dp[std::lower_bound(dp + 1, dp+ ans+ 1, a[i].second) - dp] = a[i].second;
	std::cout << ans << std::endl;
}