//【P2839】畅通工程 - 洛谷 - 0
#include <iostream>
#include <algorithm>

const int MAXN = 1000;

int f[MAXN + 5][MAXN + 5];
bool vis[MAXN + 5];

void dfs(int v, int n) {
	vis[v] = true;
	for (int i = 1; i <= n; ++i) {
		if (f[v][i] && !vis[i])
			dfs(i, n);
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	register int a, b;
	for (register int i = 0; i < m; ++i) {
		std::cin >> a >> b;
		f[a][b] = f[b][a] = 1;
	}
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			++tot;
			dfs(i, n);
		}
	}
	std::cout << --tot << std::endl;
}