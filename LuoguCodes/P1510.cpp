//【P1510】精卫填海 - 洛谷 - 0
#include <iostream>
#include <algorithm>

const char* out = "Impossible";
const int kMaxN = 10000;
int k[kMaxN + 5] = { 0 }, m[kMaxN + 5] = { 0 };
int f[kMaxN + 5] = { 0 };

int main() {
	int v, n, c;
	std::cin >> v >> n >> c;
	for (int i = 1; i <= n; ++i)
		std::cin >> k[i] >> m[i];
	for (int i = 1; i <= n; ++i)
		for (int j = c; j >= m[i]; --j)
			f[j] = std::max(f[j], f[j - m[i]] + k[i]);
	for (int i = 1; i <= c; ++i)
		if (f[i] >= v) {
			std::cout << c - i << std::endl;
			return 0;
		}
	std::cout << out << std::endl;
}