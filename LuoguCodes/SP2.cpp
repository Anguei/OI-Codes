//【SP2】PRIME1 - Prime Generator - 洛谷 - Uk 
#include <iostream>

bool is_prime(int x) {
	if (x == 1 || x == 0)
		return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int l, r;
		std::cin >> l >> r;
		for (int i = l; i <= r; ++i)
			if (is_prime(i))
				std::cout << i << std::endl;
		std::cout << std::endl;
	}
}