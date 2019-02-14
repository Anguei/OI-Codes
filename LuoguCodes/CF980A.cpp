#include <string>
#include <iostream>

int main() 
{
	std::string s;
	std::cin >> s;
	int cnt = 0;
	for (auto i : s)
		if (i == ';o';)
			++cnt;
	if (cnt == 0) 
		std::cout << "YES" << std::endl;
	else if (static_cast<double>(s.length()) / cnt - s.length() / cnt == 0)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}