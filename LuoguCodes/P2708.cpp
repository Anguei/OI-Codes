//【P2708】硬币翻转 - 洛谷 - 100
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::getline(std::cin, s);
	int ans = 0;
	for (register unsigned i = 1; i < s.size(); ++i)
		ans += (s[i] + s[i - 1]) % 2;
	std::cout << ans + !(s.back() - 48) << std::endl;
}