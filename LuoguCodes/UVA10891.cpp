//【UVA10891】Game of Sum - 洛谷 - Wa
#include <cstring>
#include <vector>
#include <iostream> 
#include <algorithm>

const int kMaxN = 100;

int a[kMaxN + 5];
int sum[kMaxN + 5];
int dp[kMaxN + 5][kMaxN + 5];

int work(int i, int j)
{
	if (dp[i][j])
		return dp[i][j];
	int min = 0;
	for (int k = i; k < j; ++k)
		min = std::min(min, work(i, k));
	for (int k = i + 1; k <= j; ++k)
		min = std::min(min, work(k, j));
	return dp[i][j] = sum[j] - sum[i - 1] - min;
}

int main()
{
	int n;
	while (std::cin >> n && n)
	{
		sum[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			std::cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		int min = 0; 
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= n; ++j)
			{
				for (int k = i; k < j; ++k)
					min = std::min(min, dp[i][k]);
				for (int k = i + 1; k <= j; ++k)
					min = std::min(min, dp[k][j]);
				dp[i][j] = sum[j] - sum[i - 1] - min;
			}
		//std::cout << dp[1][n] << std::endl;
		memset(dp, 0, sizeof dp);
		std::cout << 2 * work(1, n) - sum[n] << std::endl;
	}
}