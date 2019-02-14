// luogu-judger-enable-o2
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 1000000 + 5, mod = 100003;

int n, m;
int depth[N], cnt[N];
bool vis[N];
std::vector<int> g[N];

void bfs() {
	depth[1] = 0; vis[1] = true; cnt[1] = 1;
	std::queue<int> q;
	q.push(1);
	
	while (!q.empty()) {
		int to = q.front(); q.pop();
		for (auto &e : g[to]) {
			int to2 = e;
			if (!vis[to2]) {
				vis[to2] = true;
				depth[to2] = depth[to] + 1;
				q.push(to2);
			}
			if (depth[to2] == depth[to] + 1) {
				cnt[to2] = (cnt[to] + cnt[to2]) % mod;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	bfs();
	
	for (int i = 1; i <= n; ++i)	
		std::cout << cnt[i] << std::endl;
}