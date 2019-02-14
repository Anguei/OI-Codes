#include <iostream>

using ll = long long;

ll qpow(ll a, ll b, ll mod)
{
	ll res = 1; // Silly Bug: ll res = 0;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

int main()
{
	ll n, m, k, x;
	std::cin >> n >> m >> k >> x;
	std::cout << (x % n + m % n * qpow(10, k, n) % n + n) % n << std::endl;
}