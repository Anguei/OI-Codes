#pragma GCC optimize(3)
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

const int kMaxM = 20000;

struct Data
{
	int w, h;
} data[kMaxM + 5];

int dp[kMaxM + 5];

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	
	while (T--)
	{
		memset(data, 0, sizeof data);
		memset(dp, 0, sizeof dp);
		
		int m;
		std::cin >> m;
		for (int i = 1; i <= m; ++i)
		{
			std::cin >> data[i].w >> data[i].h;
			dp[i] = 1;
		}
		
		for (int i = 1; i <= m; ++i)
			for (int j = i + 1; j <= m; ++j)
				if (data[i].w < data[j].w && data[i].h < data[j].h)
					dp[j] = std::max(dp[j], dp[i] + 1);
			
		int ans = 0;		
		for (int i = 1; i <= m; ++i)
			ans = std::max(ans, dp[i]);
		std::cout << ans - 1 << std::endl;
							
	}
}