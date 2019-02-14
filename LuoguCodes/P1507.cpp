//【P1507】NASA的食物计划 - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

const int MAXN = 50, MAXV = 400, MAXM = 400;
int v[MAXN + 5], m[MAXN + 5], c[MAXN + 5];
int f[MAXV + 5][MAXM + 5];

int main() {
	int V, M;
	std::cin >> V >> M;
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> v[i] >> m[i] >> c[i];
	for (int i = 1; i <= n; ++i)
		for (int j = V; j >= v[i]; --j)
			for (int k = M; k >= m[i]; --k)
				f[j][k] = std::max(f[j][k], f[j - v[i]][k - m[i]] + c[i]);
	std::cout << f[V][M] << std::endl;
}