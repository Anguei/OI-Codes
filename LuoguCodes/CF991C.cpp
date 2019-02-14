//【CF991C】Candies - 洛谷 - Ac 
#include <iostream>
#include <algorithm>

using ll = long long;

ll n, v, rest, l, r, mid;

int ok(ll x)
{
	v = 0;
	rest = n;
	while (rest > 0)
	{
		v += std::min(x, rest);
		rest -= std::min(x, rest);
		rest -= rest / 10;
	}
	return (v * 2 >= n);
}

int main()
{
	std::cin >> n;
	l = 1, r = n;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (ok(mid))
			r = mid;
		else
			l = mid + 1;
	}
	std::cout << l << std::endl;
}