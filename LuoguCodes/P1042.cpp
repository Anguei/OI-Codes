//【P1042】乒乓球 - 洛谷 - 40
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

int main()  {
	int w, l;
	w = l = 0;
	char c;
	std::vector<char> vec;
	c = std::cin.get();
	while (c != ';E';) {
		if (c != 10) vec.push_back(c);
		if (c == ';W';) ++w;
		if (c == ';L';) ++l;
		if (w >= 11 || l >= 11)
			if (w - l >= 2 || l - w >= 2) {
				std::cout << w << ';:'; << l << std::endl;
				w = l = 0;
			}
		c = std::cin.get();
	}
	std::cout << w << ';:'; << l << std::endl;
	std::cout << std::endl;
	w = l = 0;
	std::string s(vec.size(), '; ';);
	for (int i = 0; i < s.size(); ++i) {
		s[i] = vec[i];
	}
	for (auto c : s) {
		if (c == ';W';) ++w;
		if (c == ';L';) ++l;
		if (w >= 21 || l >= 21) 
			if (w - l >= 2 || l - w >= 2) {
				std::cout << w << ';:'; << l << std::endl;
				w = l = 0;
			}
	}
	std::cout << w << ';:'; << l << std::endl;
}