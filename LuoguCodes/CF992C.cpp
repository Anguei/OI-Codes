//【CF992C】Nastya and a Wardrobe - 洛谷 - Wa
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using ull = unsigned long long;

const ull kMod = 1000000000 + 7;

ull qpow(ull a, ull b)
{
	ull ans = 1;
    while (b) 
    {
        if (b & 1)
            ans = ans * a % kMod;
        a = a * a % kMod;
        b >>= 1;
    }
    return ans;
}

int main()
{
	ull x, k;
	std::cin >> x >> k;
	if (k == 0)
	{
		std::cout << (x * 2) % kMod << std::endl;
	}
	else if (x == 0)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		ull powed = qpow(2, k);
		x = x * 2 % kMod;
		std::cout << (powed * x - powed + 1 + kMod) % kMod << std::endl; 
		return 0;
	}
}
// 348612312017571993 87570063840727716 551271547
// 1000000007 1 1000000006