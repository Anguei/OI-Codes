//【P2388】阶乘之乘 - 洛谷 - 80
#include <iostream>

int main() {
	long long n;
	std::cin >> n;
	long long temp = 0, ans = 0;
	for (long long i = 1; i <= n; ++i) {
		long long bak = i;
		while (!(bak % 5)) {
			++temp;
			bak /= 5;
		}
		ans += temp;
	}
	std::cout << ans << std::endl;
}