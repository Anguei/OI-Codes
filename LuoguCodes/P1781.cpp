//【P1781】宇宙总统 - 洛谷 - 0
#include <iostream> 
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::string max;
	int maxl, maxp, cnt;
	maxl = maxp = cnt = 0;
	while (std::cin >> s && ++cnt)
		if (s.length() > maxl)
			maxl = s.length(), maxp = cnt, max = s;
		else if (s.length() == maxl)
			if (s > max)
				maxp = cnt, max = s;
		else
			continue;
	std::cout << maxp << std::endl << max << std::endl;
}