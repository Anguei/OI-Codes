//【CF983A】Finite or not - 洛谷 - Wa
#include <cctype>
#include <cstdio> 
#include <iostream>
#include <algorithm>

using ll = long long;

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

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

const char *solve(ll p, ll q, ll b)
{
	if (!p)
		return "Finite";
	ll g = gcd(p, q);
	q /= g;
	while ((g = gcd(q, b)) ^ 1) 
	{
		while (q % g == 0) 
			q /= g;
		b = g;
	}
	return q == 1 ? "Finite" : "Infinite";
}

int main()
{
	int T = read();
	while (T--)
	{
		ll p = read(), q = read(), b = read();
		puts(solve(p, q, b));
	}
} 