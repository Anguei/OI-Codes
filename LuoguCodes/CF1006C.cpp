//【CF1006C】Three Parts of the Array - 洛谷 - Ac
#include <vector>
#include <iostream>
#include <algorithm>

using ll = long long;

int main()
{
	int n;
	std::cin >> n;
	std::vector<ll> a(n + 1), s(n + 1), s2(n + 2);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i], s[i] = s[i - 1] + a[i];
	for (int i = n; i >= 1; --i)
		s2[i] = s2[i + 1] + a[i];
	ll ans = 0;
	for (int l = 1, r = n; l < r;)
	{
		if (s[l] < s2[r])
			++l;
		else if (s[l] > s2[r])
			--r;
		else if (s[l] == s2[r])
			ans = std::max(ans, s[l]), ++l, --r;
	}
	std::cout << ans << std::endl;
}