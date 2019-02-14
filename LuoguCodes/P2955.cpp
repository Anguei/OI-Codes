//【P2955】[USACO09OCT]奇数偶数Even Odd - 洛谷 - 40
#include <iostream>
#include <string> 

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::string t;
		std::cin >> t;
		std::cout << (t[t.size() - 1] % 2 == 0 ? "even" : "odd") << std::endl;
	}
}