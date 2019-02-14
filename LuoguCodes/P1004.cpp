#include <iostream>
#include <algorithm>

int map[11][11];
int dp[11][11][11][11];

int main()
{
	int n;
	std::cin >> n;
	int a, b, c;
	while (std::cin >> a >> b >> c && a && b && c)
		map[a][b] = c;			
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				for (int l = 1; l <= n; ++l)
				{
					int a = dp[i - 1][j][k - 1][l];
					int b = dp[i][j - 1][k][l - 1];
					int c = dp[i - 1][j][k][l - 1];
					int d = dp[i][j - 1][k - 1][l];
					dp[i][j][k][l] = map[i][j] + map[k][l] + std::max(std::max(a, b), std::max(c, d));
					if (i == k && j == l)
						dp[i][j][k][l] -= map[i][j];
				}
	std::cout << dp[n][n][n][n] << std::endl;
}