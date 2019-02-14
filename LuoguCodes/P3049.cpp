//【P3049】[USACO12MAR] 园林绿化 Landscaping - 洛谷 - Uk
#include <cmath> 
#include <vector>
#include <iostream>
#include <algorithm>

const int kMaxN = 100;
const int kMaxElement = 1000;

int aa[kMaxN + 5], bb[kMaxN + 5];
int dp[kMaxElement + 5][kMaxElement + 5];

int main()
{
	int n, x, y, z;
	std::cin >> n >> x >> y >> z;
	for (int i = 1; i <= n; ++i)
		std::cin >> aa[i] >> bb[i];
	std::vector<int> a, b;
	for (int i = 1; i <= n; ++i)	
	{
		while (aa[i]--)
			a.emplace_back(i);
		while (bb[i]--)
			b.emplace_back(i);
	}
	
	for (unsigned i = 1; i <= a.size(); ++i) 
		dp[i][0] = i * y;
	for (unsigned i = 1; i <= b.size(); ++i)
		dp[0][i] = i * x;
	
	for (unsigned i = 1; i <= a.size(); ++i)	
		for (unsigned j = 1; j <= b.size(); ++j)
			dp[i][j] = std::min(std::min(dp[i - 1][j] + y, dp[i][j - 1] + x), dp[i - 1][j - 1] + z * std::abs(a[i] - b[j]));
	
	std::cout << dp[a.size() - 1][b.size() - 1] << std::endl;
}