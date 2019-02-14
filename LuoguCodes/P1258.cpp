//【P1258】小车问题 - 洛谷 - 0 
#include <cstdio>

#include <iostream>

int main() {
	double s, a, b;
	std::cin >> s >> a >> b;
	printf("%.6f", 2 * s / (3 * a + b) + s / b - 2 * a * s / (3 * a * b + b * b));
	std::cout << std::endl;
}