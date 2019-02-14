//【P3197】[HNOI2008]越狱 - 洛谷 - Uk
#include <iostream>
#include <algorithm>

using ll = long long;

int qpow(ll a, ll b, ll mod)
{
	ll res = 1;
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
	ll a, b, mod = 100003;	
	std::cin >> a >> b;
	ll all = qpow(a, b, mod) % mod;
	ll no = (a % mod) * (qpow(a - 1, b - 1, mod) % mod) % mod;
	std::cout << ((all - no) < 0 ? all - no + mod : all - no) << std::endl;
}