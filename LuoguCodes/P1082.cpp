#include <iostream>
#include <algorithm>

using ll = long long;

void exGcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return;
	}
	exGcd(b, a % b, y, x);
	y -= a / b * x; 
}

int main()
{
	// ax % b = 1 的最小整数解 
	ll a, b, x = 0, y = 0;
	std::cin >> a >> b;
	exGcd(a, b, x, y);
	std::cout << (x % b + b) % b << std::endl; // 防负数 
}