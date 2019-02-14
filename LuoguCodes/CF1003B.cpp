//【CF1003B】Binary String Constructing - 洛谷 - Ac
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int a, b, x, n;
	std::cin >> a >> b >> x;
	n = a + b;
	int restA, restB, restX;
	restA = a, restB = b;
	std::vector<char> s(n + 1);
	
	if (a > b)
	{
		std::cout << "0";
		--restA;
		for (int i = 2; i <= x; ++i)
			if (i & 1)
				printf("0"), --restA;
			else
				printf("1"), --restB;
		if (x & 1)
			std::cout << std::string(restA, ';0';) + std::string(restB, ';1';);
		else
			std::cout << std::string(restB, ';1';) + std::string(restA, ';0';);
	}
	else
	{
		std::cout << "1";
		--restB;
		for (int i = 2; i <= x; ++i)
			if (!(i & 1))
				printf("0"), --restA;
			else
				printf("1"), --restB;
		if (x & 1)
			std::cout << std::string(restB, ';1';) + std::string(restA, ';0';);
		else
			std::cout << std::string(restA, ';0';) + std::string(restB, ';1';);
	}
	std::cout << std::endl;
	
	/*
	for (int i = 0; i <= n; ++i)
	{
		if (cntX < x)
		{
			if (i == 1 || s[i - 1] == ';1';)
				s[i] = ';0';, ++cntA;
			else if (s[i - 1] == ';0';)
				s[i] = ';1';, ++cntB;
			++cntX;
		}
		else if (cntA < a)
			s[i] = ';0';, ++cntA;
		else if (cntB < b)
			s[i] = ';1';, ++cntB;
	}
	for (int i = 1; i <= n; ++i)
		std::cout << s[i];
	std::cout << std::endl;
	*/
}