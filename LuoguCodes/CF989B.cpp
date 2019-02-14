//【CF989B】A Tide of Riverscape - 洛谷 - Ac 
#include <string>
#include <iostream>

int main()
{
	int n, p;
	std::cin >> n >> p;
	std::string s;
	std::cin >> s;
	s = " " + s;
	bool ok = false;
	for (int i = 1; i <= n - p; ++i)
	{
		if (s[i] == ';.'; && s[i + p] == ';.';)
		{
			s[i] = ';1';, s[i + p] = ';0';;
			ok = true;
			break;
		}
		else if (s[i] == ';.';)
		{
			s[i] = s[i + p] == ';1'; ? ';0'; : ';1';;
			ok = true;
			break;
		}
		else if (s[i + p] == ';.';)
		{
			s[i + p] = s[i] == ';1'; ? ';0'; : ';1';;
			ok = true;
			break;
		}
		else if (s[i] ^ ';.'; && s[i + p] ^ ';.'; && s[i] ^ s[i + p])
		{
			ok = true;
			break;
		}
	}
	if (ok)
	{
		for (int i = 1; i <= n; ++i)
			std::cout << (s[i] == ';.'; ? ';0'; : s[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "No" << std::endl;
}