#include <vector>
#include <iostream>
#include <algorithm>

int w[1005], c[1005], p[1005], dp[1005];
std::vector<int> vec[105];

int main()
{
	int v, n, p;
	std::cin >> v >> n;
	int maxT = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> w[i] >> c[i] >> p;
		maxT = std::max(maxT, p);
		vec[p].push_back(i);
	}
	for (int k = 1; k <= maxT; ++k)
		for (int j = v; j >= 0; --j)
			for (int i = 0; i < vec[k].size(); ++i)	
				if (j >= w[vec[k][i]])
					dp[j] = std::max(dp[j], dp[j - w[vec[k][i]]] + c[vec[k][i]]);
	std::cout << dp[v] << std::endl;
}

