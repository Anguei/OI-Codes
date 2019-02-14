#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, d;
	std::cin >> n >> d;
	std::vector<int> x(n + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> x[i];
	int ans = 2;
	for (int i = 1; i < n; ++i)
	{
		if (x[i + 1] - x[i] < d * 2)
			continue;
		if (x[i + 1] - x[i] == d * 2)
			++ans;
		else
			ans += 2;
	}
	std::cout << ans << std::endl;
}