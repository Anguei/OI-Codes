//【P1508】Likecloud-吃、吃、吃 - 洛谷 - 0
#include <iostream>
#include <algorithm>

const int MAXN = 200, MAXM = 200;
int a[MAXN + 5][MAXM + 5], f[MAXN + 5][MAXM + 5];

int main() {
	int n, m;
	std::cin >> n >> m;
	int x = n, y = m / 2 + 1;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) std::cin >> a[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) f[i][j] = std::max(std::max(f[i - 1][j], f[i - 1][j + 1]), f[i - 1][j - 1]) + a[i][j];
	std::cout << (std::max(f[x][y], std::max(f[x][y - 1], f[x][y + 1]))) << std::endl;
}