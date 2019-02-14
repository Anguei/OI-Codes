//【P2320】[HNOI2006]鬼谷子的钱袋 - 洛谷 - 0
#include <iostream> 
#include <algorithm>

int a[10000 + 5];

int main() {
	int m, sum = 1;
	std::cin >> m;
	a[1] = 1, --m;
	while (m - 2 * a[sum] >= 0) {
		a[sum + 1] = a[sum] * 2;
		m -= a[sum + 1];
		++sum;
	}
	if (m == a[sum]) {
		--a[sum];
		++m;
	}
	if (m != 0)
		a[++sum] = m;
	std::cout << sum << std::endl;
	std::sort(a + 1, a + sum + 1);
	for (int i = 1; i <= sum; ++i) 
		std::cout << a[i] << " ";
}