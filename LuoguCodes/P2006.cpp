//【P2006】赵神牛的游戏 - 洛谷 - 70
#include <iostream>

int main() {
	long long k, m, n;
	std::cin >> k >> m >> n;
	bool can = false;
	for (int i = 1; i <= m; ++i) {
		long long a, b;
		std::cin >> a >> b;
		if (a == 0)
			std::cout << i << " ";
		if (a != 0 && k / a * b >= n) {
			std::cout << i << " ";
			can = true;
		}
	}
	if (!can)
		std::cout << -1;
	std::cout << std::endl;
}