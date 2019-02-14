//【P2330】[SCOI2005] 繁忙的都市 - 洛谷 - 10
#include <iostream>
#include <algorithm>

struct Edge {
	int u;
	int v;
	int c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
	Edge() {}
};

constexpr int kMaxN = 300;
constexpr int kMaxM = 50000;

Edge e[kMaxM + 5];
int fa[kMaxN + 5];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	fa[v] = u;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) // 又一次忘记初始化并查集 
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u;
		int v;
		int c;
		std::cin >> u >> v >> c;
		e[i] = Edge(u, v, c);
	}
	std::sort(e + 1, e + m + 1, [](const Edge &e1, const Edge &e2) {
		return e1.c < e2.c;
	});
	
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
		if (find(e[i].u) != find(e[i].v)) { // sillyBug
			merge(e[i].u, e[i].v);
			if (++cnt == n - 1) {
				std::cout << n - 1 << " " << e[i].c << std::endl;
				return 0;
			}
		}
}