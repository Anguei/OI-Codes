//【CF409A】The Great Game - 洛谷 - Uk
#include <string>
#include <iostream>

int main() {
	std::string s1, s2;
	int cnt1 = 0, cnt2 = 0;
	std::cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i)
		if (s1[i] == s2[i])
			continue;
		else if (s1[i] == ';8';) 
			if (s2[i] == ';[';)
				cnt1++;
			else
				cnt2++;
		else if (s1[i] == ';[';)
			if (s2[i] == ';(';)
				cnt1++;
			else
				cnt2++;
		else if (s1[i] == ';(';)
			if (s2[i] == ';8';)
				cnt1++;
			else
				cnt2++;
	if (cnt1 == cnt2)
		std::cout << "TIE" << std::endl;
	else if (cnt1 > cnt2)
		std::cout << "TEAM 1 WINS" << std::endl;
	else if (cnt2 > cnt1) 
		std::cout << "TEAM 2 WINS" << std::endl;
	
	return 0;
}