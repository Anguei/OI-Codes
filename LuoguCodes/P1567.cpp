//【P1567】统计天数 - 洛谷 - 0 
#include <iostream>
#include <algorithm>

int a[10000005], f[10000005];

int main() {
	int n;
	std::cin >> n;
	for (register int i = 0; i < n; ++i) 
		std::cin >> a[i];
	f[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			f[i] = f[i - 1] + 1;
		}
		else {
			f[i] = 1;
		}
	}
	std::sort(f, f + n, std::greater<int>());
	std::cout << f[0] << std::endl;
}