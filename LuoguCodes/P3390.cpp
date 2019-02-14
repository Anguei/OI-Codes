#include <cstring>
#include <iostream>
#include <algorithm>

using ll = long long;
const int N = 100 + 5;

struct Matrix
{
	ll a[N][N];
} a, ans;

ll n, b;//, mod = 1000000000 + 7;
#define mod 1000000007

Matrix operator * (const Matrix x, const Matrix y)
{
	Matrix res;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			res.a[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				res.a[i][j] = (res.a[i][j] + (x.a[i][k] * y.a[k][j]) % mod) % mod;
	return res;
}

int main()
{
	std::cin >> n >> b;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			std::cin >> a.a[i][j];
			
	for (int i = 1; i <= n; ++i)
		ans.a[i][i] = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			std::cout << ans.a[i][j] << " ";
		std::cout << std::endl;
	}
}