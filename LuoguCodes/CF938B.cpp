//【CF938B】Run For Your Prize - 洛谷 - Uk
#include <vector>
#include <iostream>

int a[1000000];

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t;
		std::cin >> t;
		a[t] = 1;
	}
	for (int l = 1, r = 1000000, time = 0, already = 0; already <= n; ++l, --r, ++time) {
		if (a[l])
			++already;
		if (a[r])
			++already;
		if (already == n) {
			std::cout << time << std::endl;
			return 0;
		}
	}
}