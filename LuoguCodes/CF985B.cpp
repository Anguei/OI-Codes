//【CF985B】Switches and Lamps - 洛谷 - Ac
#include <cstdio>
#include <string>
#include <vector> 
#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n + 1);
	std::vector<int> b(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		//a[i] = " " + a[i];
		for (int j = 1; j <= m; ++j)
		{
			b[j] += a[i][j - 1] - 48;
		}
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (b[j] - a[i][j - 1] + 48 == 0)
			{
				break; // 有关着的，不可行 
			}
			if (j == m)
			{
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
		
	std::cout << "NO"  << std::endl;
	/*for (int i = 1; i <= m; ++i)
	{
		b[i] = 0;
		for (int j = 1; j <= n; ++j)
			b[i] += a[j][i - 1] - 48;
	}*/
	
	/*for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;
			bool ok = true;
			for (int k = 1; k <= m; ++k)
				if ((b[k] - a[j][k - 1]) % 2 == 0)
					ok = false;
			if (ok)
			{
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
			
	std::cout << "NO" << std::endl;
}*/
}