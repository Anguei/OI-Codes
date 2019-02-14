//【UVA1225】Digit Counting - 洛谷 - Uk
#include <map>
#include <string>
#include <iostream>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::string s = "";
		for (int i = 1; i <= n; ++i)
			s += std::to_string(i);
		std::map<char, int> map;
		for (const auto &i : s)
			++map[i];
		for (int i = 0; i <= 8; ++i)
			std::cout << map[i + 48] << " ";
		std::cout << map[9 + 48] << std::endl;
	}
}