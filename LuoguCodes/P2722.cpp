//【P2722】总分 Score Inflation - 洛谷 - 0
#include <iostream>
#include <algorithm>

int p[10005], t[10005], f[100005];

int main() {
	int n, m;
	std::cin >> m >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> p[i] >> t[i];
	for (int i = 1; i <= n; ++i)
		for (int j = t[i]; j <= m; ++j)
			f[j] = std::max(f[j], f[j - t[i]] + p[i]);
	std::cout << f[m] << std::endl;
}