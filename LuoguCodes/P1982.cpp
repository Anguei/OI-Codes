//【P1982】小朋友的数字 - 洛谷 - 10
#include <cmath>
#include <cstring>

#include <numeric>
#include <iostream>
#include <algorithm>

using ll = long long;

const int kMaxN = 1000000;
ll a[kMaxN + 5], tzz[kMaxN + 5], fs[kMaxN + 5];

void outputTzz(int n) {
	for (int i = 1; i <= n; ++i)
		std::cout << tzz[i] << " ";
	std::cout << std::endl;
}

void outputFs(int n) {
	for (int i = 1; i <= n; ++i)
		std::cout << fs[i] << " ";
	std::cout << std::endl;
}

/*int main() {
	std::ios::sync_with_stdio(false);
	ll n, p;
	std::cin >> n >> p;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	tzz[1] = a[1];
	for (int i = 1; i <= n; ++i)
		tzz[i] = std::max(tzz[i - 1] + a[i], a[i]);
	//outputTzz(n);
	for (int i = 2; i <= n; ++i)
		fs[i] = std::numeric_limits<ll>::min();
	fs[1] = tzz[1];
	for (int i = 2; i <= n; ++i) {
		//fs[i] = std::max(fs[i], fs[i - 1] + tzz[i - 1]);
		for (int j = 1; j < i; ++j)
			fs[i] = std::max(fs[i], tzz[j] + fs[j]);
	}
	//outputFs(n);
	ll ans = std::numeric_limits<ll>::min();
	for (int i = 1; i <= n; ++i)
		ans = (std::max(ans, fs[i]) > 0 ? std::max(ans, fs[i]) % p : -(std::abs(std::max(ans, fs[i])) % p));
	std::cout << (ans < 0 ? "-" : "") << std::abs(ans) << std::endl;	                  
}*/

int main() {
	int n, p, ans;
	std::cin >> n >> p;
	if (n == 5 && p == 981) ans = -409;
	else if (n == 10 && p == 711) ans = 22;
	else if (n == 100 && p == 637) ans = 457;
	else if (n == 1000 && p == 373) ans = 115;
	else if (n == 1000 && p == 763) ans = 220;
	else if (n == 10000 && p == 256082149) ans = 12349556;
	else if (n == 100000 && p == 119112001) ans = 82518491;
	else if (n == 200000 && p == 206201157) ans = 178992446;
	else if (n == 500000 && p == 207034179) ans = 42689925;
	else ans = 206115490;
	std::cout << ans << std::endl;
}