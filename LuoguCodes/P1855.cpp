//【P1855】榨取kkksc03 - 洛谷 - 0 
#include <iostream>
#include <algorithm>

int n, M, T, m[105], t[105], f[205][205];

int main() {
	std::cin >> n >> M >> T;
	for (int i = 1; i <= n; ++i)
		std::cin >> m[i] >> t[i];
	for (int i = 1; i <= n; ++i) 
		for (int j = M; j >= m[i]; --j)
			for (int k = T; k >= t[i]; --k)
				f[j][k] = std::max(f[j][k], f[j - m[i]][k - t[i]] + 1);
	std::cout << f[M][T] << std::endl;
}