//【P1736】创意吃鱼法 - 洛谷 - 100
#include <cstdio>
#include <cstring>

#include <limits>
#include <iostream>
#include <algorithm>

const int kMaxNM = 2500;
int a[kMaxNM + 5][kMaxNM + 5], f[kMaxNM + 5][kMaxNM + 5], sumRaw[kMaxNM + 5][kMaxNM + 5], sumCol[kMaxNM + 5][kMaxNM + 5];;

int main() {
	std::ios::sync_with_stdio(false);
	int n, m, ans = std::numeric_limits<int>::min();
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			std::cin >> a[i][j];
			if (!a[i][j]) {
				sumRaw[i][j] = sumRaw[i][j - 1] + 1;
				sumCol[i][j] = sumCol[i - 1][j] + 1;
			} else
				f[i][j] = std::min(f[i - 1][j - 1] + 1, std::min(sumRaw[i][j - 1], sumCol[i - 1][j]) + 1);
			ans = std::max(ans, f[i][j]);
		}
	
	std::memset(f, 0, sizeof f);
	std::memset(sumRaw, 0, sizeof sumRaw);
	std::memset(sumCol, 0, sizeof sumCol);
	
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= 1; --j) {
			if (!a[i][j]) {
				sumRaw[i][j] = sumRaw[i][j + 1] + 1;
				sumCol[i][j] = sumCol[i - 1][j] + 1;
			}
			else
				f[i][j] = std::min(f[i - 1][j + 1] + 1, std::min(sumRaw[i][j + 1], sumCol[i - 1][j]) + 1);
			ans = std::max(ans, f[i][j]);
		}
	std::cout << ans << std::endl;
}