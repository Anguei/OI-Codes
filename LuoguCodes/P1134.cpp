//【P1134】阶乘问题 - 洛谷 - 70
#include <iostream> 

int main() {
	register int n;
	std::cin >> n;
	register long long res = 1;
	for (register int i = 1; i <= n; ++i) {
		res *= i;
		while (res % 10 == 0)
			res /= 10;
		res %= 100000000;
	}
	std::cout << res % 10 << std::endl;
}