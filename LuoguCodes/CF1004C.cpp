#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), prefix(n + 1), suffix(n + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	long long tmp = 0, ans = 0;
	for (int i = n; i >= 1; --i)	
		tmp += static_cast<bool>(++suffix[a[i]] == 1);
	for (int i = 1; i <= n; ++i)
	{
		tmp -= static_cast<bool>(--suffix[a[i]] == 0);
		ans += tmp * static_cast<bool>(++prefix[a[i]] == 1);
	}
	std::cout << ans << std::endl;
}