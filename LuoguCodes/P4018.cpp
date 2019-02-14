//【P4018】RoyOctober 之取石子 - 洛谷 - 0 
#include <iostream>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::cout << (!(n % 6) ? "Roy wins!" : "October wins!") << std::endl;
	}
}