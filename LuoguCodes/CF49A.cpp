//【CF49A】Sleuth - 洛谷 - Uk 
#include <cctype>

#include <set>
#include <string>
#include <iostream>

int main() {
	std::set<char> set {';A';, ';E';, ';I';, ';O';, ';U';, ';a';, ';e';, ';i';, ';o';, ';u';, ';y';,';Y';};
	std::string string;
	std::getline(std::cin, string);
	for (int i = string.size() - 1; i >= 0; --i) {
		if (isalpha(string[i])) {
			//std::clog << string[i] << " ";
			std::cout << (set.count(string[i]) ? "YES" : "NO") << std::endl;
			return 0;
		}
	}
}