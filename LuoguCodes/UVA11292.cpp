//【UVA11292】Dragon of Loowater - 洛谷 - Ac 
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;
	while (std::cin >> n >> m && n && m)
	{
		std::vector<int> d(n), a(m);
		for (int i = 0; i < n; ++i)
			std::cin >> d[i];
		for (int i = 0; i < m; ++i)
			std::cin >> a[i];
		if (n > m)
			std::cout << "Loowater is doomed!" << std::endl;
		else
		{
			std::sort(d.begin(), d.end());
			std::sort(a.begin(), a.end());
			//std::cout << std::accumulate(a.begin(), a.begin() + d.size(), 0) << std::endl;
			int cnt = 0, tot = 0;
			for (int i = 0; i < m; ++i)
				if (a[i] >= d[cnt])
				{
					tot += a[i];
					if (++cnt == n)
						break;
				}
			if (cnt < n)
				std::cout << "Loowater is doomed!" << std::endl;
			else
				std::cout << tot << std::endl;
		}
	}	 
} 