//【CF988B】Substrings Sort - 洛谷 - Ac 
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main() 
{
	int n;
	std::cin >> n;
	std::vector<std::string> vec;
	for (int i = 0; i < n; ++i)	
	{
		std::string tmp;
		std::cin >> tmp;
		vec.emplace_back(tmp);
	}
	std::sort(vec.begin(), vec.end(), [](const std::string  &s1, const std::string &s2)
	{
		return s1.size() < s2.size();
	});
	for (int i = 0; i < n - 1; ++i)
	{
		std::string s1 = vec[i], s2 = vec[i + 1];
		if (s2.find(s1) == std::string::npos)
		{
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	std::cout << "YES" << std::endl;
	for (const auto &i : vec)
		std::cout << i << std::endl;
}