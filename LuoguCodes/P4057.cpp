//【P4057】「CodePlus 2017 11 月赛」晨跑 - 洛谷 - 100
#include <iostream>

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

ull lcm(ull a, ull b, ull c) 
{
	return a * b / gcd(a, b) * c / gcd(a * b / gcd(a, b), c);
}

int main()
{
	ull a, b, c, ans;
	std::cin >> a >> b >> c;
	std::cout << lcm(a, b, c) << std::endl;
}