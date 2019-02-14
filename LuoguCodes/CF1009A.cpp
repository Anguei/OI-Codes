#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> c(n + 1), a(m + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i];
	for (int i = 1; i <= m; ++i)
		std::cin >> a[i];
	if (a[0] < c[0])
	{
		std::cout << "0" << std::endl;
		return 0;
	}
	int ans = 0, pos1 = 1, pos2 = 1;
	while (pos1 <= n && pos2 <= m)
	{
		if (c[pos1] <= a[pos2])
		{
			++pos1;
			++pos2;
			++ans;
		}
		else
			++pos1;
	}
	std::cout << ans << std::endl;
}