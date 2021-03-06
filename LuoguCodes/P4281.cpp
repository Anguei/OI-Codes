// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "1832"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

/*struct Edge {
    int v, w;
    Edge() {} // = default;
    Edge(int v, int w) : v(v), w(w) {}
};*/

struct Edge {
    int v, next;
    Edge() = default;
    Edge(int v, int next) : v(v), next(next) {}
};

const int N = 500000 + 5;
int n, q, cnt = 0, depth[N], parent[20][N], head[N];
// std::vector<int> g[N];
Edge edge[N << 1];

void addE(int u, int v) {
    edge[++cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

void dfs(int u, int fa) {
    parent[0][u] = fa;
    for (int i = 1; (1 << i) <= depth[u]; ++i) {
        parent[i][u] = parent[i - 1][parent[i - 1][u]];
    }
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    per(i, 20, 0) {
        if (depth[u] <= depth[v] - (1 << i)) {
            v = parent[i][v];
        }
    }
    if (u == v) return u;
    per(i, 20, 0) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int disTree(int u, int v, int xx) {
    return depth[u] + depth[v] + depth[xx] - depth[lca(u, v)] - (depth[lca(lca(u, v), xx)] << 1);
}

void solution() {
    n = read(); q = read();
    rep(i, 2, n) {
        int u = read(), v = read();
        // g[u].push_back(v); g[v].push_back(u);
        addE(u, v); addE(v, u);
    }
    depth[1] = 1; dfs(1, 1);
    while (q--) {
        int a = read(), b = read(), c = read();
        int fA = lca(a, b), fB = lca(b, c), fC = lca(a, c);
        int dA = disTree(a, b, c), dB = disTree(b, c, a), dC = disTree(a, c, b);
        if (dA > dB) dA = dB, fA = fB;
        if (dA > dC) dA = dC, fA = fC;
        print(fA), pc('; ';), print(dA), puts("");
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}