#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n, b;
    std::cin >> n >> b;
    std::vector<int> a(n + 1), dp(b + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    int flag = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        flag += (a[i] & 1 ? 1 : -1);
        if (!flag)
        {
            int cost = abs(a[i] - a[i + 1]);
            for (int j = b; j >= cost; --j)
                dp[j] = std::max(dp[j], dp[j - cost] + 1);
        }
    }
    std::cout << dp[b] << std::endl;
}