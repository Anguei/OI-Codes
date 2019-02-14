//【P1808】单词分类_NOI导刊2011提高（01） - 洛谷 - 0 
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
	register std::string s;
	std::set<std::string> set;
	register unsigned n;
	std::cin >> n;
	for (register unsigned i = 0; i ^ n; ++i) {
		std::cin >> s;
		std::sort(s.begin(), s.end());
		set.insert(s);
	}
	std::cout << set.size() << std::endl;
}