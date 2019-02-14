#include <iostream>
#include <algorithm>
#define dbg(x) std::clog << #x << " = " << (x) << std::endl;

using ll = int64_t;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	} else {
		ll ans = exgcd(b, a % b, x, y);
		ll oldX = x;
		x = y;
		y = oldX - a / b * y;
		return ans;
	}
}

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int main() {
	ll a, b, c, ansX, ansY;
	std::cin >> a >> b >> c;
	ll moded = exgcd(a, b, ansX, ansY);
	if (c % moded) 
		return std::cout << -1 << std::endl, 0;
	ansX *= -c / moded;
	ansY *= -c / moded;
	ll border = 5 * qpow(10, 18);
#ifdef yyfLocal
	dbg(border);
#endif
	if (ansX <= border && ansY <= border && ansX >= -border && ansY >= -border)
		std::cout << ansX << " " << ansY << std::endl;
	else
		std::cout << -1 << std::endl;
}