//【AT998】3 歩進んで 2 歩下がる - 洛谷 - Wa 
#include <iostream>

int main()
{
	using ll = long long;
	ll n;
	std::cin >> n;
	std::cout << n / 2 + (n & 1 ? 3 : 0) << std::endl;
}