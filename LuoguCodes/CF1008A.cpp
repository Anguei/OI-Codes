#include <cctype>
#include <set>
#include <vector> 
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	std::string s;
	std::cin >> s;
	for (auto &i : s)
		if (isupper(i))
			i += 32;
	std::set<char> set = { ';a';, ';e';, ';i';, ';o';, ';u'; };
	for (int i = 0; i < s.size() - 1; ++i)
		if (!set.count(s[i]) && s[i] != ';n'; && !set.count(s[i + 1]))
		{
			std::cout << "No" << std::endl;
			return 0;
		}
	if (!set.count(s.back()) && s.back() != ';n';)
		std::cout << "No" << std::endl;
	else
		std::cout << "Yes" << std::endl;
}