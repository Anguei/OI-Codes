//【P1598】垂直柱状图 - 洛谷 - 0 
#include <iostream> 
#include <string>
#include <map>
#include <algorithm>

int main() {
	std::map<char, int> m;
	std::string s;
	for (int i = 1; i < 5; ++i) {
		s.clear();
		getline(std::cin, s);
		for (auto i : s)
			if (i != '; ';)
				++m[i];
	}
	int maxn = 0;
	for (int i = 0; i < 26; ++i)
		maxn = std::max(maxn, m[i + 65]);
	char* starn = new char[26];
	for (int i = 0; i < 26; ++i) {
		starn[i] = m[i + 65];
	}
	for (int i = 1; i <= maxn; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (maxn - i + 1 == starn[j]) {
				std::cout.put(';*';);
				std::cout.put(32);
				--starn[j];
			}
			else {
				//std::cout << " " << " ";
				std::cout.put(32);
				std::cout.put(32);
			}
		}
		std::cout.put(10);
	}
	std::cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << std::endl;
}