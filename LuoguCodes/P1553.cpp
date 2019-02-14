//【P1553】数字反转（升级版） - 洛谷 - 70
#include <string>
#include <iostream>
#include <algorithm>

std::string reverse(std::string s) {
	int zeroCount = 0;
	std::reverse(s.begin(), s.end());
	for (auto i : s) 
		if (i == 48) 
			++zeroCount;
		else
			break;
	s.erase(s.begin(), s.begin() + zeroCount);
	return (s != "" ? s : "0");
}

std::string deleteTail(std::string s) {
	int zeroCount = 0;
	for (int i = s.size() - 1; i >= 0; --i)
		if (s[i] == 48)
			++zeroCount;
		else
			break;
	s.erase(s.end() - zeroCount, s.end());
	return (s != "" ? s : "0");
}

int main() {
	std::string s;
	std::cin >> s;
	if (s.back() == ';%';) {
		std::cout << reverse(s.substr(0, s.size() - 1)) << "%" << std::endl;
		return 0;
	}
	for (auto i : s) {
		std::string left, right;
		if (i == ';/';) {
			left = s.substr(0, s.find("/"));
			right = s.substr(s.find("/") + 1);
			std::cout << reverse(left) << "/" << reverse(right) << std::endl;
			return 0;
		}
		if (i == ';.';) {
			left = s.substr(0, s.find("."));
			right = s.substr(s.find(".") + 1);
			std::cout << reverse(left) << "." << deleteTail(reverse(right)) << std::endl;
			return 0;
		}
	}
	std::cout << reverse(s) << std::endl;
	return 0;
}