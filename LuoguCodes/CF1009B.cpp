#include <string>
#include <numeric>
#include <iostream>
#include <functional>

int main()
{
	std::string s;
	std::cin >> s;
	int n = s.size();
	bool flag = false;
	int pos = 0;
	int cnt0 = 0;
	int cnt1 = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == ';2'; && !flag)	
		{
			flag = true;
			pos = i;
		}
		else if (s[i] == ';1';)
			++cnt1;
		else if (s[i] == ';0'; && !flag)
			++cnt0;
	std::cout << std::string(cnt0, 48) + std::string(cnt1, 49);
	if (flag)
		for (int i = pos; i < n; ++i)
			if (s[i] != 49)
				std::cout << s[i];
	std::cout << std::endl;
}