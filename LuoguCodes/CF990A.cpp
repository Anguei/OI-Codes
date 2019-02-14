//¡¾CF990A¡¿Commentary Boxes - Âå¹È - Ac
#include <iostream>
#include <algorithm>

using ll = long long;

int main()
{
	ll n, m, a, b;
	std::cin >> n >> m >> a >> b;
	ll moded = n % m;
	ll dived = n / m;
	if (moded == 0)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	ll ans1 = 0, ans2 = 0;
	ans1 = ((dived + 1) * m - n) * a;
	ans2 = (n - dived * m) * b;
	//std::clog << ans1 << " " << ans2 << std::endl;
	std::cout << std::min(ans1, ans2) << std::endl;
}