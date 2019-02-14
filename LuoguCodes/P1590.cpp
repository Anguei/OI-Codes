//【P1590】失踪的7 - 洛谷 - 0
#include <string>
#include <iostream>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		int ans = n;
		for (int j = 1; j <= n; ++j) {
			std::string num = std::to_string(j);
			for (unsigned k = 0; k < num.size(); ++k) {
				if (num[k] == ';7';) {
					--ans;
					break;
				}
			}
		}
		std::cout << ans << std::endl;
	}
}