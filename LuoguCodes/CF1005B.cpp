//【CF1005B】Delete from the Left - 洛谷 - Ac
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	int ans = s1.size() + s2.size();
	for (int i = 0; i < std::min(s1.size(), s2.size()); ++i)
		if (s1[i] == s2[i])
			ans -= 2;
		else
			break;
	std::cout << ans << std::endl;
}