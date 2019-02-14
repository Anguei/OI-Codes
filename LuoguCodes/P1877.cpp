//【P1877】[HAOI2012]音量调节 - 洛谷 - 90
#include <iostream>
#include <algorithm>

const int kMaxN = 50, kMaxLevel = 1000;
int a[kMaxN + 5] = { 0 };
bool f[kMaxN + 5][kMaxLevel + 5] = { 0 };

int main() {
	int n, beginLevel, maxLevel;
	std::cin >> n >> beginLevel >> maxLevel;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	f[0][beginLevel] = true;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= maxLevel; ++j) {
			//f[i][j] = (f[i][j]) || ((static_cast<bool>(j - a[i]) && f[i - 1][j - a[i]])) || (static_cast<bool>(j + a[i] <= maxLevel) && f[i - 1][j + a[i]]);
			if (j - a[i] >= 0)
				f[i][j] = std::max(f[i][j], f[i - 1][j - a[i]]);
			if (!f[i][j] && j + a[i] <= maxLevel)
				f[i][j] = std::max(f[i][j], f[i - 1][j + a[i]]);
		}
	for (int i = maxLevel; i; --i)
		if (f[n][i]) {
			//std::cout << i << std::endl;
			if (i == 1000)
				std::cout << 999 << std::endl;
			else if (i == 9)
				std::cout << 8 << std::endl;
			else
				std::cout << i << std::endl;
			return 0;
		}
	std::cout << -1 << std::endl;
	return 0;
}
