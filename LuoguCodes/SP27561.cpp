//【SP27561】GDCOFTI - Greatest Common Divisor Of Three Integers - 洛谷 - Uk
#include <iostream>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int x, y, z;
	std::cin >> x >> y >> z;
	std::cout << gcd(x, gcd(y, z)) << std::endl;
}