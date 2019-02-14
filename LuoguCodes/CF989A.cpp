//【CF989A】A Blend of Springtime - 洛谷 - Ac 
#include <string>
#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;
	for (int i = 1; i < s.length() - 1; ++i)
		if (s[i - 1] != ';.'; && s[i] != ';.'; && s[i + 1] != ';.'; && s[i - 1] != s[i] && s[i + 1] != s[i] && s[i - 1] != s[i + 1])
		{
			std::cout << "Yes" << std::endl;
			return 0;
		}
	std::cout << "No" << std::endl;
}