//【CF25A】IQ test - 洛谷 - Uk 
#include <iostream>

int main() {
	int n, t, p1, p2, f = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		if (t % 2) ++f, p1 = i;
		else p2 = i;
	}
	if (f == 1) std::cout << p1 + 1 << std::endl;
	else std::cout << p2 + 1 << std::endl;
}