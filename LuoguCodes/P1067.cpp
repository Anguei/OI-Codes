//【P1067】多项式输出 - 洛谷 - 0
#include <cstdio> 
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	for (int i = n; i >= 0; --i) {
		int a;
		std::cin >> a;
		if (!a) 
			continue;
		if (i != n && a > 0) // first
			printf("+");
		if (a < 0) {
			//printf("-%d", -a);
			printf("-");
			a *= -1;
		}
		if (!i || a != 1)
			std::cout << a;
		if (i)
			std::cout << ';x';;
		if (i > 1)
			printf("^%d", i);
	}
}