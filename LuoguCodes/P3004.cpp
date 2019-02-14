//【P3004】[USACO10DEC] 宝箱 Treasure Chest - 洛谷 - 90
#include <iostream>
#include <algorithm>

const int kMaxN = 5000;

int sum[kMaxN + 5];
int dp[kMaxN + 5][kMaxN + 5];

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		std::cin >> tmp;
		dp[i][i] = tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	for (int i = n- 1; i >= 1; --i)
		for (int j = i + 1; j <= n; ++j)
			dp[i][j] = std::max(sum[j] - sum[i - 1] - dp[i + 1][j], sum[j] - sum[i - 1] - dp[i][j - 1]);
	
	std::cout << dp[1][n] << std::endl;
}