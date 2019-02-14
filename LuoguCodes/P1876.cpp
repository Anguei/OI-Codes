//【P1876】开灯 - 洛谷 - 0
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::cout << "1 ";
	for (int i = 2; i * i <= n; ++i)
		std::cout << i * i << " ";
	std::cout << std::endl;
}