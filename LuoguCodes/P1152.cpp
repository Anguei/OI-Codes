//【P1152】欢乐的跳 - 洛谷 - 0
#include <cmath>
#include <iostream>
#include <algorithm>

const int kMaxN = 10000;
int a[kMaxN + 5] = { 0 }, f[kMaxN + 5] = { 0 };

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 1; i <= n - 1; ++i)
		f[i] = abs(a[i] - a[i + 1]);
	std::sort(f + 1, f + n);
	for (int i = 1; i < n; ++i)
		if (f[i] != i) {
			std::cout << "Not jolly" << std::endl;
			return 0;
		}
	std::cout << "Jolly" << std::endl;
}