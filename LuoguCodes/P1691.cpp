// luogu-judger-enable-o2
//【P1691】有重复元素的排列问题 - 洛谷 - 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<std::string> v;
	std::sort(s.begin(), s.end());
	do {
		v.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	for (auto &i : v)
		std::cout << i << std::endl;
	std::cout << v.size() << std::endl;
}