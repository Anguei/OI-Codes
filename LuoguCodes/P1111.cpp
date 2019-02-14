// luogu-judger-enable-o2
//【P1111】修复公路 - 洛谷 - 100
#include <array>
#include <iostream>
#include <algorithm>

const int kMaxN = 1000;
const int kMaxM = 100000;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    Edge() {}
};

std::array<Edge, kMaxM + 5> e;
std::array<int, kMaxN + 5> fa;

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
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        e[i] = Edge(u, v, w);
    }
    std::sort(e.begin() + 1, e.begin() + m + 1, [](const Edge &e1, const Edge &e2) {
        return e1.w < e2.w;
    });
    
    int tot = 0, cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (find(e[i].u) != find(e[i].v)) {
            merge(e[i].u, e[i].v);
            // 因为输入的 w 是什么时候修完而不是需要多长时间，所以是 + 而不是 += 
            tot = e[i].w;
            if (++cnt == n - 1) {
                std::cout << tot << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
}