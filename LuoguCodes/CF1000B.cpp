#pragma GCC optimize(3)
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 5), open(n + 5), close(n + 5);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	a[n + 1] = m;
	for (int i = 1; i <= n + 1; ++i)
		if (i & 1) 
			open[i] = a[i] - a[i - 1] + open[i - 1], 
			close[i] = close[i - 1];
		else 
			close[i] = a[i] - a[i - 1] + close[i - 1], 
			open[i] = open[i - 1];
	int ans = open[n + 1];
	for (int i = 0; i <= n + 1; ++i)
		if (!(i == 0 and a[1] == 1) or (i == n + 1 and a[n] == m - 1) or (a[i] - 1 == a[i - 1] and a[i] + 1 == a[i + 1]))
			ans = std::max(ans, open[i] - close[i] + close[n + 1] - 1);
	std::cout << ans << std::endl;
}