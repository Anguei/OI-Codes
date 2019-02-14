//【P1387】最大正方形 - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

const int MAXN = 100, MAXM = 100;
bool a[MAXN + 5][MAXM + 5];
int f[MAXN + 5][MAXM + 5];

int main() {
	int n, m, ans = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) std::cin >> a[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (!a[i][j]) continue; else f[i][j] = std::min(f[i - 1][j - 1], std::min(f[i - 1][j], f[i][j - 1])) + 1;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) ans = std::max(ans, f[i][j]);
	std::cout << ans << std::endl;
}