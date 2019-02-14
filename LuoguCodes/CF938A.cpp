//【CF938A】Word Correction - 洛谷 - Wa
#include <set>
#include <string>
#include <iostream>

int main() {
	std::set<char> set { ';a';, ';e';, ';i';, ';o';, ';u';, ';y'; };
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (set.count(s[i]) && set.count(s[i - 1]))
			;
		else
			std::cout << s[i];
	std::cout << std::endl;
}