//【P1006】传纸条 - 洛谷 - Uk 
#include <iostream>
#include <algorithm>

int a[55][55];
int dp[55][55][55][55];

int main()
{
	int m, n;
	std::cin >> m >> n;
	for (int i = 1; i <= m; ++i)	
		for (int j = 1; j <= n; ++j)
			std::cin >> a[i][j];
	for (int i = 1; i <= m; ++i)	
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= m; ++k)
				for (int l = 1; l <= n; ++l)
					dp[i][j][k][l] = (i == k || j == l ? 0 : a[i][j] + a[k][l]) + std::max(std::max(dp[i][j - 1][k][l - 1], dp[i - 1][j][k - 1][l]), std::max(dp[i - 1][j][k][l - 1], dp[i][j - 1][k - 1][l]));
	std::cout << dp[m][n][m][n] << std::endl;
}
