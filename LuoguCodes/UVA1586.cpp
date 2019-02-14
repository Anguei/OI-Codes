//【UVA1586】Molar mass - 洛谷 - Uk
#include <cstdio>
#include <cctype>

#include <map>
#include <string>
#include <iostream>

int main() {
	int T;
	std::cin >> T;
	std::map<char, double> map;
	map[';C';] = 12.01;
	map[';H';] = 1.008;
	map[';O';] = 16.00;
	map[';N';] = 14.01;
	while (T--) {
		std::string s;
		std::cin >> s;
		double ans = 0;
		for (int i = 0; i < s.size(); ++i)
			if (isalpha(s[i])) {
				int num = 0;
				if (!isalpha(s[i + 1])) {
					for (int j = i + 1; j < s.size(); ++j)
						if (isdigit(s[j]))
							num = num * 10 + s[j] - 48;
						else
							break;
					ans += map[s[i]] * num;
				} 
				else
					ans += map[s[i]] * (num = 1);
				//std::clog << num << " ";
			}
		if (isalpha(s.back()))
			ans += map[s.back()];
		std::printf("%.3f\n", ans);
	}
}