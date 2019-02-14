//【CF47A】Triangular numbers - 洛谷 - Wa
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		if (i * i + i == 2 * n) {
			std::cout << "YES" << std::endl;
			return 0;
		}
	std::cout << "NO" << std::endl;
}