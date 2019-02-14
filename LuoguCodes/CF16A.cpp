//【CF16A】Flag - 洛谷 - Uk 
#include <string>
#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	char last = 0;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		char c = s.front();
		if (last == c) { std::cout << "NO" << std::endl; return 0; }
		for (auto i : s) if (i != s.front()) { std::cout << "NO" << std::endl; return 0; }
		last = c;
	}
	std::cout << "YES" << std::endl;
}