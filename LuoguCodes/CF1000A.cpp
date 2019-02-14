#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::map<std::string, int> m;
	std::string tmp;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		++m[tmp];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		if (m[tmp])
			--m[tmp];
		else
			++ans;
	}
	std::cout << ans << std::endl;
}