//【P3741】honoka的键盘 - 洛谷 - 72
#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int ans = 0;
	bool yyf = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ';V'; && s[i + 1] == ';K';) ++ans;
		if (s[i] == ';V'; && s[i + 1] == ';V'; && s[i + 2] != ';K';) yyf = 1;
		if (s[i] == ';K'; && s[i + 1] == ';K'; && s[i - 1] != ';V';) yyf = 1;
	}
	std::cout << yyf + ans << std::endl;
}