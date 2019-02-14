//【P1164】小 A 点菜 - 洛谷 - 0
#include <iostream> 
#include <algorithm>

int main() {
	int n, m;
	std::cin >> n >> m;
	int *a = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	int *f = new int[10000 + 5];
	for (int i = 0; i < 10000 + 5; ++i)
		f[i] = 0;
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= a[i]; --j)
			f[j] += f[j - a[i]];
	std::cout << f[m] << std::endl;
}