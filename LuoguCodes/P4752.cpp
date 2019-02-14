#pragma GCC optimize(3)
#include <cctype>
#include <cstdio>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>

using ll = __int128;
//using ll = long long;

bool isp(ll x)
{
	ll s = sqrt(x);
	if (x == 0 || x == 1)
		return false;
	for (int i = 2; i <= s; ++i)
		if (x % i == 0)
			return false;
	return true;
}

ll read()
{
	ll res = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
	{
		res = res * 10 + ch - 48;
		ch = getchar();
	}
	return res;
}

int main() 
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	//std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--)
	{
		int n, m;
		std::cin >> n >> m;
		ll A = 1, B = 1, C = 1;
		std::vector<ll> a, b;
		for (int i = 0; i < n; ++i)
			a.emplace_back(read());
		for (int i = 0; i < m; ++i)
			b.emplace_back(read());
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		for (int i = 0; i < m; ++i)
		{
			C *= a[i];
			C /= b[i];
		}
		for (int i = m; i < n; ++i)
			C *= a[i];
		//C = A / B;
		//std::clog << C << std::endl;
		puts(isp(C) ? "YES" : "NO");
	}
}