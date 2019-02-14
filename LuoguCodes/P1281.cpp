#include <cstring>
#include <iostream>
#include <algorithm>

const int kMaxKM = 500;

int page[kMaxKM + 5];
int sum[kMaxKM + 5];
int dp[kMaxKM + 5][kMaxKM + 5];


void log(char *s)
{
#ifndef ONLINE_JUDGE
	std::cout << s << std::endl;
#endif
}

int getSum(int l, int r)
{
	return sum[r] - sum[l - 1];
}

void print(int x, int ans) {
    if(!x) 
		return;
    for (int i = x; i >= 0; --i)
	{
        if(sum[x] - sum[i - 1] > ans || !i)
		{
            print(i, ans);
            std::cout << i + 1 << " " << x << std::endl;
            return;
        }
    }
}

int main()
{
	memset(dp, 0x3f, sizeof dp);
	int m, k;
	std::cin >> m >> k;
	for (int i = 1; i <= m; ++i)
	{
		std::cin >> page[i];
		sum[i] = sum[i - 1] + page[i];
		dp[1][i] = sum[i];
	}
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= m; ++j)
			for (int kk = 1; kk <= j; ++kk)
				dp[i][j] = std::min(dp[i][j], std::max(dp[i - 1][kk - 1], getSum(kk, j)));
	print(m, dp[k][m]);
}