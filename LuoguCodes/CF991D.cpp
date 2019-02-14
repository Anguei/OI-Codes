//【CF991D】Bishwock - 洛谷 - Ac 
#include <string>
#include <iostream>

int main()
{
	int ans = 0;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	for (unsigned i = 0; i < s1.size(); ++i)
	{    
		// 1
		if (s1[i] == 48 and s2[i] == 48 and s1[i + 1] == 48 and s2[i + 1] != 0)
		{
			++ans;
			s1[i] = s2[i] = s1[i + 1] = 88;
		}
		// 2
		if (s1[i] == 48 and s2[i] != 0 and s1[i + 1] == 48 and s2[i + 1] == 48)
		{
			++ans;
			s1[i] = s1[i + 1] = s2[i + 1] = 88;
		}
		// 3
		if (s1[i] != 0 and s2[i] == 48 and s1[i + 1] == 48 and s2[i + 1] == 48)
		{
			++ans;
			s2[i] = s1[i + 1] = s2[i + 1] = 88;
		}
		// 4
		if (s1[i] == 48 and s2[i] == 48 and s1[i + 1] != 0 and s2[i + 1] == 48)
		{
			++ans;
			s1[i] = s2[i] = s2[i + 1] = 88;
		}		
	}
	std::cout << ans << std::endl;
}