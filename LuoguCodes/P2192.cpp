//【P2192】HXY玩卡片 - 洛谷 - 0
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main() {
	int n;
	std::cin >> n;
	int *a = new int[n];
	int nn = n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::map<int, int> m;
	for (int i = 0; i < n; ++i) {
		++m[a[i]];
	}
	if (!m[0]) {
		std::cout << -1 << std::endl;
		return 0;
	}
	if (m[5] < 9) {
		std::cout << 0 << std::endl;
		return 0;
	}
	for (int i = 0; i < m[5] / 9; ++i) {
		std::cout << 555555555;
	}
	for (int i = 0; i < m[0]; ++i) {
		std::cout << 0;
	}
	std::cout << std::endl;
	return 0;
}