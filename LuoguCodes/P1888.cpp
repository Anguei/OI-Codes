//【P1888】三角函数 - 洛谷 - 80
#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int max = std::max(std::max(a, b), c);
	int min = std::min(std::min(a, b), c);
	int t = gcd(max, min);
	max /= t;
	min /= t;
	std::cout << min << "/" << max << std::endl;
}