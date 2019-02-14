#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

const int kMaxN = 99;

char map[4 + 5][kMaxN + 5];

int main() 
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 99 + 5; ++j)
			map[i][j] = ';.';;
	int n, k;
	std::cin >> n >> k;
	if (k == 0)
	{
		std::cout << "YES" << std::endl;
		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 1; j <= n; ++j)
				std::cout << ".";
			std::cout << std::endl;
		}
		return 0;
	} 
	if (k % 2)
	{
		map[2][n / 2 + 1] = ';#';;
		--k;
	}
	//int pos = 2;
	for (int i = 2; i <= 4 - 1; ++i)
	{
		for (int j = 2; j < n / 2 + 1; ++j)
		{
			if (k <= 0) 
				goto output;
			map[i][j] = map[i][n - j + 1] = ';#';;
			k -= 2;
		} 
	}
	if (k == 2)
		map[2][n / 2 + 1] = map[3][n / 2 + 1] = ';#';;
	output:
	std::cout << "YES" << std::endl;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= n; ++j)
			std::cout << map[i][j];
		std::cout << std::endl;
	}
}