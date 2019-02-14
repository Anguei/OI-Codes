//【P1030】求先序排列 - 洛谷 - 0
#include <string>
#include <iostream>
#include <algorithm>

void work(std::string s1, std::string s2) {
	if (!s1.empty()) {
		std::cout << s2.back();
		std::string::size_type pos = s1.find(s2.back());
		work(s1.substr(0, pos), s2.substr(0, pos));
		work(s1.substr(pos + 1), s2.substr(pos, s1.size() - pos - 1));
	}
}

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	work(s1, s2);
	std::cout << std::endl;
}