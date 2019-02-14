//【CF1005D】Polycarp and Div 3 - 洛谷 - Ac
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

int dp[3][200005];

int main()
{
	std::string s;
	std::cin >> s;
	int n = s.size();
	memset(dp, 0x80, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int k = (s[i - 1] - 48) % 3;
		dp[k][i] = std::max(dp[0][i - 1] + 1, std::max(dp[1][i - 1], dp[2][i - 1]));
		for (int j = 0; j < 3; ++j) 
			dp[(k + j) % 3][i] = std::max(dp[(k + j) % 3][i], dp[j][i - 1]);
	}
	int ans = std::max(dp[0][n] + 1, std::max(dp[1][n], dp[2][n])) - 1;
	std::cout << ans << std::endl;
}