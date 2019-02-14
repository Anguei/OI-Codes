//【P1547】Out of Hay - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

const int kMaxM = 10000;
struct Edge {
	int u, v, w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	Edge() {}
} e[kMaxM + 5];
int fa[kMaxM + 5];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	int U = find(u), V = find(v);
	fa[V] = fa[U];
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		e[i] = Edge(u, v, w);
	}
	std::sort(e + 1, e + m + 1, [](const Edge &e1, const Edge &e2) {
		return e1.w < e2.w;
	});
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	
	int ans = 0, cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if (find(e[i].u) != find(e[i].v)) {
			ans = std::max(ans, e[i].w);
			merge(find(e[i].u), find(e[i].v));
			if (++cnt == n - 1) 
				break;
		}
	}
	std::cout << ans << std::endl;
}