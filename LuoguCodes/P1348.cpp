//【P1348】Couple number - 洛谷 - 30
#include <cmath>
#include <iostream>
#include <algorithm>

int main() {
	long long n1, n2;
	std::cin >> n1 >> n2;
	int max = std::max(n1, n2), ans = 0;;
	for (register long long i = n1; i <= n2; ++i)
		if (abs(i) % 4 != 2) ++ans;
	std::cout << ans << std::endl;
}