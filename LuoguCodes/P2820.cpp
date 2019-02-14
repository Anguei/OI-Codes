//【P2820】局域网 - 洛谷 - 100 
#include <iostream>
#include <algorithm>

const int kMaxN = 100;
const int kMaxK = kMaxN * kMaxN;

struct Edge {
	int u, v, w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	Edge() {}
};

int fa[kMaxN + 5];
Edge e[kMaxK + 5];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	int U = find(u);
	int V = find(v);
	fa[V] = U;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	int sum = 0;
	for (int i = 1; i <= k; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		sum += w;
		e[i] = Edge(u, v, w);
	}
	std::sort(e + 1, e + k + 1, [](const Edge &e1, const Edge &e2) {
		return e1.w < e2.w;
	});
		
	int tot = 0, cnt = 0;
	for (int i = 1; i <= k; ++i) {
		if (find(e[i].u) != find(e[i].v)) {
			merge(e[i].u, e[i].v);
			tot += e[i].w;
			if (++cnt == n - 1) {
				std::cout << sum - tot << std::endl;
				return 0;
			}
		}
	}
}