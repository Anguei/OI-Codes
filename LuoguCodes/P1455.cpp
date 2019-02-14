//【P1455】搭配购买 - 洛谷 - 30
#include <iostream>
#include <algorithm>

const int kMaxN = 10000, kMaxM = 5000, kMaxW = 10000;
int c[kMaxN + 5], d[kMaxN + 5], fa[kMaxN + 5];
int dp[kMaxW + 5];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

int main() {
	int n, m, w;
	std::cin >> n >> m >> w;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i] >> d[i];
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		int U = find(u), V = find(v);
		if (U != V) {
			fa[V] = U;
			c[U] += c[V];
			d[U] += d[V];
			c[V] = d[V] = 0;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (c[i] || d[i])
			for (int j = w; j >= c[i]; --j)
				dp[j] = std::max(dp[j], dp[j - c[i]] + d[i]);
	std::cout << dp[w] << std::endl;
}