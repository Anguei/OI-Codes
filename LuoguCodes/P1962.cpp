#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; ++i)

using ll = long long;

struct Matrix
{
	ll m[3][3];
} ans, x, tmp;

ll n, mod = 1000000007;
//ll ans[3][3], x[3][3], tmp[3][3];

/*void mul_ans()
{
	rep(i, 1, 2) rep(j, 1, 2)
		tmp[i][j] = ans[i][j], ans[i][j] = 0;
	rep(i, 1, 2) rep(j, 1, 2) rep(k, 1, 2)
		ans[i][j] = (ans[i][j] + tmp[i][k] * x[j][k] % mod) % mod;
}

void mul_x()
{
	rep(i, 1, 2) rep(j, 1, 2)
		tmp[i][j] = x[i][j], x[i][j] = 0;
	rep(i, 1, 2) rep(j, 1, 2) rep(k, 1, 2)
		x[i][j] = (x[i][j] + tmp[i][k] * tmp[k][j] % mod) % mod;
}*/

Matrix operator * (const Matrix &x, const Matrix &y)
{
	Matrix res;
	rep(i, 1, 2) rep(j, 1, 2)
		res.m[i][j] = 0;
	rep(i, 1, 2) rep(j, 1, 2) rep(k, 1, 2)
		res.m[i][j] = (res.m[i][j] + x.m[i][k] * y.m[k][j] % mod) % mod;
	return res;
}

void qpow(ll b)
{
	while (b)
	{
		if (b & 1)
			ans = ans * x; //mul_ans();
		x = x * x; //mul_x();
		b >>= 1;
	}
}

void print()
{
	int fib[3], out[3];
	fib[1] = fib[2] = 1;
	out[1] = out[2] = 0;
	rep(i, 1, 2) rep(j, 1, 2)
		out[i] = (out[i] + ans.m[i][j] * fib[j] % mod) % mod;
	std::cout << out[1] << std::endl;
}

int main()
{
	std::cin >> n;
	if (n <= 2)
		return std::cout << 1 << std::endl, 0;
	ans.m[1][1] = ans.m[2][2] = 1;
	x.m[1][1] = x.m[1][2] = x.m[2][1] = 1;
	x.m[2][2] = 0;
	qpow(n - 2);
	print();
}