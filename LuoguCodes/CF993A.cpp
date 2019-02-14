//【CF993A】Two Squares - 洛谷 - Wa
#include <cmath>
#include <iostream>
#include <algorithm>

int main()
{
	int s1[8], s2[8];
	for (int i = 0; i < 8; ++i)
	{
		std::cin >> s1[i];
		s1[i] *= 2;
	}
	for (int i = 0; i < 8; ++i)
	{
		std::cin >> s2[i];
		s2[i] *= 2;
	}

	int cs1x = (s1[0] + s1[2] + s1[4] + s1[6]) / 4;
	int cs1y = (s1[1] + s1[3] + s1[5] + s1[7]) / 4;
	int cs2x = (s2[0] + s2[2] + s2[4] + s2[6]) / 4;
	int cs2y = (s2[1] + s2[3] + s2[5] + s2[7]) / 4;
	int s = abs(s1[0] - cs1x);
	int d = abs(s2[0] + s2[2] - 2 * cs2x);
	int dis = abs(cs1x - cs2x) + abs(cs1y - cs2y);

	bool ok;
	if (dis > 2 * s + d)
		ok = false;
	else
	{
		if (abs(cs1y - cs2y) <= s + d && abs(cs1x - cs2x) <= s + d)
			ok = true;
		else
			ok = false;
	}

	std::cout << (ok ? "YES" : "NO") << std::endl;
}
