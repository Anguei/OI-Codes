//【P1150】Peter的烟 - 洛谷 - 0
#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	int ans = n;
	while (n / k) {
		ans += n / k;
		n = n / k + n % k;
	}
	std::cout << ans << std::endl;
}