//【P1403】[AHOI2005]约数研究 - 洛谷 - 30
#include <iostream>
int main() {
	int n, ans = 0;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		ans += n / i;
	std::cout << ans << std::endl;
}