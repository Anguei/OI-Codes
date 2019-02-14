#include <cstring>
#include <vector> 
#include <iostream>
#include <algorithm>

const int N = 200 + 5;

std::vector<int> g[N];
int color[N];

bool dfs(int now) {
	for (auto &to : g[now]) {
		if (color[to] == color[now]) {
			return false;
		} else if (!color[to]) {
			color[to] = 3 - color[now];
			if (!dfs(to)) return false;
		}
	}
	return true;
}

int main() {
	int n;
	while (std::cin >> n && n) {
		for (auto &i : g) i.clear();
		memset(color, 0, sizeof color);
		int m;
		std::cin >> m;
		while (m--) {
			int u, v;
			std::cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		color[0] = 1;
		puts(dfs(0) ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}	
}