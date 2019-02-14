#include <string>
#include <iostream>
#include <algorithm>

const int mod = 19260817;

using ll = long long;

ll qpow(ll a, ll b)
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
	std::string s1, s2;
	std::cin >> s1 >> s2;
	ll a = 0, b = 0;
	for (auto i : s1) a = (a * 10 + i - 48) % 19260817;
	for (auto i : s2) b = (b * 10 + i - 48) % 19260817;
	if (b == 0) std::cout << "Angry!" << std::endl;
	else std::cout << (a * qpow(b, mod - 2) % mod + mod) % mod << std::endl;
}