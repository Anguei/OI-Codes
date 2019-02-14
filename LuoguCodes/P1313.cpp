//【P1313】计算系数 - 洛谷 - 80
#include <cmath>

#include <iostream>

using ll = long long;

const int kMod = 10007;
const int kMaxK = 1000;
ll c[kMaxK + 5][kMaxK + 5];

ll C(int n, int m) {
	if (n == m) return 1;
	if (m == 0) return 1;
	if (c[n][m]) return c[n][m];
	return c[n][m] = (C(n - 1, m - 1) + C(n - 1, m)) % kMod;
}

ll qpow(ll a, ll b) {
	if (b == 1) return a % kMod;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % kMod;
		a = a * a % kMod;
		b /= 2;
	}
	return ans;
}

int main() {
	int a, b, k, n, m;
	std::cin >> a >> b >> k >> n >> m;
	//std::cout << (static_cast<ll>(std::pow(a, n) * pow(b, m)) % kMod * C(k, m) % kMod) % kMod << std::endl;
	std::cout << ((((qpow(a, n) % kMod) * qpow(b, m)) % kMod)* C(k, m)) % kMod << std::endl;
}