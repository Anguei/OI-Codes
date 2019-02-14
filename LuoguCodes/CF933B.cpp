//【CF933B】A Determined Cleanup - 洛谷 - Uk
#include <iostream>

using ll = long long;

int main() {
	long long n, k;
	std::cin >> n >> k;
	k = -k;
	long long cnt = 0;
	long long ans[2000 + 5] = { 0 };
	while (n) {
		ans[cnt] = n % k;
		n /= k;
		if (ans[cnt] < 0) {
			ans[cnt] -= k;
			++n;
		}
		++cnt;
	}
	std::cout << cnt << std::endl;
	for (ll i = 0; i < cnt; ++i)
		std::cout << ans[i] << " ";
	std::cout << std::endl;
} 