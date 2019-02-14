//【P1482】Cantor表（升级版） - 洛谷 - 20
#include <cstdio> 
#include <iostream> 

inline int gcd(int a, int b) {
	if (b == 0) 
		return a;
	return (gcd(b, a % b));
}

int main() {
	int a, b, c, d;
	scanf("%d/%d %d/%d", &a, &b, &c, &d);
	a *= c, b *= d;
	int t = gcd(a, b);
	a /= t, b /= t;
	std::cout << b << " " << a << std::endl;
}