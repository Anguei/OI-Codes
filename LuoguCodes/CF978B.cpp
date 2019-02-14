//【CF978B】File Name - 洛谷 - Ac 
#include <string>
#include <iostream>

int main() 
{
	int size;
	std::cin >> size;
	std::string s;
	std::cin >> s;
	int ans = 0;
	for (int i = 2; i < size; ++i)
	{
		if (s[i] == ';x'; && s[i - 1] == ';x'; && s[i - 2] == ';x';)
			++ans;
	}
	std::cout << ans << std::endl;
}