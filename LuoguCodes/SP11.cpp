//【SP11】FCTRL - Factorial - 洛谷 - Uk 
#include <iostream>

int main() {
	long long T;
	std::cin >> T;
	while (T--) {
		long long n;
		std::cin >> n;
		long long ans = 0;
		while (n > 0)
			ans += (n /= 5);
		std::cout << ans << std::endl;
	}
}