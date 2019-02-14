//【P1057】传球游戏 - 洛谷 - Uk 
#include <iostream>
#include <algorithm>

int dp[35][35]; // dp[i][j] 表示：传了 j 次到第 i 人 
				// 每个人的球可以从两边（i + 1、i - 1）传过来 
				// dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1]

int main()
{
	int n, m;
	std::cin >> n >> m;
	dp[1][0] = 1;
	for (int i = 1; i <= m; ++i) 
	{
		dp[1][i] = dp[2][i - 1] + dp[n][i - 1];
		dp[n][i] = dp[n - 1][i - 1] + dp[1][i - 1];
		for (int j = 2; j <= n - 1; ++j)
			dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
	}
	std::cout << dp[1][m] << std::endl;
}