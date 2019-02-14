//【P3366】【模板】最小生成树 - 洛谷 - 20
#include <string>
#include <iostream>
#include <algorithm>

const int kMaxN = 5000, kMaxM = 200000;
const std::string cannot("orz");
struct Edge {
    int x, y, z;
    Edge(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    Edge() {}
};
Edge edges[kMaxM + 5]; 
int fa[kMaxN + 5];

int find(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        edges[i] = Edge(x, y, z);
    }
    std::sort(edges + 1, edges + m + 1, [](const Edge &e1, const Edge &e2) { 
		return e1.z < e2.z; 
	});
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
        
    int tot = 0, cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (find(edges[i].x) != find(edges[i].y)) {
            tot += edges[i].z;
            fa[find(edges[i].y)] = fa[(edges[i].x)];
            if (++cnt == n - 1)
                break;
        }
    }
    std::cout << (cnt == n - 1 ? std::to_string(tot) : "orz") << std::endl;
}
