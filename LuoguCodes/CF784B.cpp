//【CF784B】Kids Riddle - 洛谷 - Wa
#include <cctype>

#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	if (n == 0)
		std::cout << 1 << std::endl;
	else
	{
		static char map[] =  { ';0';, ';1';, ';2';, ';3';, ';4';, ';5';, ';6';, ';7';, ';8';, ';9';, ';A';, ';B';, ';C';, ';D';, ';E';, ';F'; };
		static int loops[] = {  1,   0,   0,   0,   1,   0,   1,   0,   2,   1,   1,   2,   0,   1,   0,   0  };
		std::string s;
		while (n)
		{
			s += map[n % 16];
			n /= 16;
		}
		std::reverse(s.begin(), s.end());
		
		int ans = 0;
		for (char i : s)
			ans += loops[(isdigit(i) ? i - 48 : i - 55)];
		std::cout << ans << std::endl;
	}
}