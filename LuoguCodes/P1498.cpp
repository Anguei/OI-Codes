//【P1498】南蛮图腾 - 洛谷 - 0
#include <iostream>
#include <string>

int main() {
	std::string ans[2052]; 
	int h = 2;
	ans[1] = " /\\ ";
	ans[2] = "/__\\";
	int n;
	std::cin >> n;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= h; ++j) {
			ans[j + h] = ans[j] + ans[j];
		}
		for (int j = 1; j <= h; ++j) {
			for (int k = 1; k <= h; ++k) {
				ans[j] = " " + ans[j] + " ";
			}
		}
		h *= 2;
	}
	for (int i = 1; i <= h; ++i) {
		std::cout << ans[i] << std::endl;
	}
}