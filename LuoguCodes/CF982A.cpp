//【CF982A】Row - 洛谷 - Ac
#include <string> 
#include <iostream>

int main()
{
	std::string s;
	std::cin >> s >> s;
	s = "0" + s + "0";
	std::cout << (s.find("000") != std::string::npos || s.find("11") != std::string::npos ? "No" : "Yes");
}