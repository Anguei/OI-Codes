//【P2979】[USACO10JAN] 奶酪塔 Cheese Towers - 洛谷 - Uk 
#include <iostream>
#include <algorithm>

const int kMaxN = 100;
const int kMaxT = 1000 * 5 / 4;

struct Cheese
{
	int h, v;
	bool isBig = false; 
} cheese[kMaxN + 5];

int dp[kMaxT + 5];

int main()
{
	int n, t, k;
	std::cin >> n >> t >> k;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> cheese[i].v >> cheese[i].h;
		if (cheese[i].h >= k)
			cheese[i].isBig = true;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = cheese[i].h; j <= t * 5 / 4; ++j)
			dp[j] = std::max(dp[j], dp[j - cheese[i].h] + cheese[i].v);
	int ans = dp[t];
	for (int i = 1; i <= n; ++i)
		if (cheese[i].isBig)
			ans = std::max(ans, dp[(t - cheese[i].h) * 5 / 4] + cheese[i].v);
	std::cout << ans << std::endl;			
}