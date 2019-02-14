// luogu-judger-enable-o2
#include <vector>
#include <iostream>
#include <algorithm>
#define dbg(x) std::cout << #x << " = " << (x) << std::endl

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	int tmp, ans;
	std::vector<int> a{ 0 };
	while (std::cin >> tmp)
		a.emplace_back(tmp);
	int n = a.size() - 1;
	std::vector<int> dp(n + 1);
	dp[1] = a[1];
	ans = 1;
	for (int i = 2; i <= n; ++i)
		if (a[i] <= dp[ans])
			dp[++ans] = a[i];
		else
			dp[std::upper_bound(dp.begin() + 1, dp.begin() + ans + 1, a[i], std::greater<int>()) - dp.begin()] = a[i];
	std::cout << ans << std::endl;
	dp[1] = a[1];
	ans = 1;
	for (int i = 2; i <= n; ++i)
		if (a[i] > dp[ans])
			dp[++ans] = a[i];
		else
			dp[std::lower_bound(dp.begin() + 1, dp.begin() + ans + 1, a[i]) - dp.begin()] = a[i];
	std::cout << ans << std::endl;
}