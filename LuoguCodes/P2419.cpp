#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	bool map[105][105] = { 0 };
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		map[a][b] = true;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				map[i][j] = (map[i][j]) | (map[i][k] & map[k][j]);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		bool ok = true;
		for (int j = 1; j <= n; ++j)
			if (i ^ j)
				ok = (ok) & (map[i][j] | map[j][i]);
		ans += ok;
	}
	std::cout << ans << std::endl;
}