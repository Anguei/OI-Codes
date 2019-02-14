//【UVA1585】Score - 洛谷 - Uk 
#include <string>
#include <iostream>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::string s;
		std::cin >> s;
		int now = 0, ans = 0;
		for (const auto &i : s) {
			if (i == ';O';)
				ans += ++now;
			else
				now = 0;
		}
		std::cout << ans << std::endl;
	}
}