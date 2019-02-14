//【P1541】乌龟棋 - 洛谷 - Uk 
#include <iostream> 
#include <algorithm>

const int kMaxN = 350, kMaxM = 120;

int a[kMaxN + 5], b[5];
//int dp[kMaxM + 5];
int dp[45][45][45][45];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 1; i <= m; ++i)
	{
		int tmp;
		std::cin >> tmp;
		++b[tmp];
	}
	
	dp[0][0][0][0] = a[1];
	
	for (int i = 0; i <= b[1]; ++i)
		for (int j = 0; j <= b[2]; ++j)
			for (int k = 0; k <= b[3]; ++k)
				for (int l = 0; l <= b[4]; ++l)
				{
					int tmp = i * 1 + j * 2 + k * 3 + l * 4 + 1;
					if (i)
						dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[tmp]);
					if (j)
						dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[tmp]);
					if (k)
						dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[tmp]);
					if (l)
						dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[tmp]);
				}
	
	std::cout << dp[b[1]][b[2]][b[3]][b[4]] << std::endl;
}