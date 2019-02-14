//【P1060】开心的金明 - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

const int MAXN = 30000, MAXM = 25;

int f[MAXN + MAXM + 5] = { 0 }, v[MAXM + 5], p[MAXM + 5];

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
		std::cin >> v[i] >> p[i];
	for (int i = 0; i < m; ++i)
		for (int j = n; j >= v[i]; --j)
			f[j] = std::max(f[j], f[j - v[i]] + p[i] * v[i]);
	std::cout << f[n] << std::endl;
}