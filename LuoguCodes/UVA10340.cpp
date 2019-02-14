//【UVA10340】All in All - 洛谷 - Uk 
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
	std::string s, t;
	while (std::cin >> s >> t) {
		std::queue<char> qs;
		for (const char &i : s)
			qs.push(i);
		for (const char &i : t)
			if (i == qs.front())
				qs.pop();
		std::cout << (qs.empty() ? "Yes" : "No") << std::endl;
	}
}