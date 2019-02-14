#include <iostream>
#include <algorithm>

int f, v;
int ans[105][105];
int a[105][105];
int dp[105][105]; // 设：dp[i][j] 表示把前 i 束花放进前 j 个花瓶所获的最大价值 

void init()
{
    std::cin >> f >> v;
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= v; ++j)
            std::cin >> a[i][j];
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= v; ++j)
            dp[i][j] = (i == j ? dp[i - 1][j - 1] + a[i][j] : -0x3f3f3f3f);
}

void print(int i, int j)
{
    if (!i)
		return;
    print(i - 1, ans[i][j] - 1);
    std::cout << ans[i] [j] << " ";
}

int main()
{
    init();
    for (int i = 1; i <= f; ++i) 
        for (int j = 1; j <= v - f + i; ++j)
            for (int k = i; k <= j; ++k)
                if (dp[i - 1][k - 1] + a[i][k] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][k - 1] + a[i][k];
                    ans[i][j] = k;
                }
    std::cout << dp[f][v] << std::endl;
    print(f, v);
}