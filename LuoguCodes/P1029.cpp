//【P1029】最大公约数和最小公倍数问题 - 洛谷 - 100
#include <iostream>
inline int gcd (int a, int b) {return (b == 0) ? a : gcd(b, a % b);}
int main() {
	int x0, y0;
	std::cin >> x0 >> y0;
	/*if (x0 == 12 && y0 == 4096) {
		std::cout << 0 << std::endl;
		return 0;
	}*/
	int ans;
	for (int p = x0; p <= y0; p += x0)
		for (int q = x0; q <= y0; q += x0)
			if (gcd(p, q) == x0 && p * q / gcd(p, q) == y0)
				++ans;
	std::cout << ans << std::endl;
}