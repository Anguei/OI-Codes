//【UVA1584】Circular Sequence - 洛谷 - Wa
#include <string>
#include <iostream>

int less(std::string s, int p, int q) {
	for (int i = 0; i < s.size(); ++i)
		if (s[(p + i) % s.size()] != s[(q + i) % s.size()])
			return s[(p + i) % s.size()] < s[(q + i) % s.size()];
	return 0;
}
int main() {
	int T;
	std::string s;
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int ans = 0;
		for (int i = 1; i < s.size(); i++)
			if (less(s, i, ans)) ans = i;
		for (int i = 0; i < s.size(); i++)
			std::cout.put(s[(i + ans) % s.size()]);
		std::cout << std::endl;
	}
}