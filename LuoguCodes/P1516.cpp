#include <utility>
#include <string>
#include <iostream>
#include <algorithm>

using ll = long long;

int ans = 0;

ll exgcd(ll a, ll b, ll &x1, ll &y1)
{
	if (b == 0)
	{
		x1 = 1;
		y1= 0;
		return a;
	}
	else
	{
		ans = exgcd(b, a % b, x1, y1);
		ll oldX = x1;
		x1 = y1;
		y1 = oldX - a / b * y1;
	}
	return ans;
}

int main()
{
	ll x, y, m, n, l;
	std::cin >> x >> y >> m >> n >> l;
	ll a = x - y, b = n - m;
	if (b < 0) a = -a, b = -b;
	ll x1, y1;
	exgcd(b, l, x1, y1);
	if (a % ans != 0)
		puts("Impossible");
	else
		std::cout << ((x1 * (a / ans)) % (l / ans) + (l / ans)) % (l / ans) << std::endl;
}