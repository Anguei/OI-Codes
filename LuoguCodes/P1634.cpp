//【P1634】禽兽的传染病 - 洛谷 - 0
#include <iostream>

int main() {
	int x, n;
	std::cin >> x >> n;
	unsigned long long ans = 1, now = 0;
	for (int i = 1; i <= n; ++i) {
		ans = ans * x + ans;
	}
	std::cout << ans << std::endl;
}