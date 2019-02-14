//【P1161】开灯 - 洛谷 - 0 
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int ans = 0;
	while (n --> 0) {
		double a;
		int t;
		std::cin >> a >> t;
		for (int i = 1; i <= t; ++i)
			ans ^= static_cast<int>(a * i);
	}
	std::cout << ans << std::endl;
}	