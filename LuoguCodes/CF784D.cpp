//【CF784D】Touchy-Feely Palindromes - 洛谷 - Uk
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
	std::map<int, std::string> map;
	map[0] = "23";
	map[1] = "10";
	map[2] = "30";
	map[3] = "11";
	map[4] = "13";
	map[5] = "12";
	map[6] = "31";
	map[7] = "33";
	map[8] = "32";
	map[9] = "21";
	std::string s1, s2, s3;
	std::cin >> s1;
	for (char i : s1)
		s2 += map[i - 48];
	s3 = s2;
	std::reverse(s2.begin(), s2.end());
	std::cout << (s2 == s3 ? "Yes" : "No") << std::endl;
}