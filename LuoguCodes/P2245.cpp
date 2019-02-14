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
#define fn "task"
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

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

const int N = 100000 + 5, M = 300000 + 5;
int n, m, Q, fa[N], depth[N], parent[25][N], w[25][N];
Edge e[M];
std::vector<Edge> g[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void kruscal() {
    int tot = 0;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int U = find(u), V = find(v); // 这里应该同时保存儿子和老子
        if (U != V) {
            fa[V] = U;
            g[u].push_back(Edge(u, v, w)); g[v].push_back(Edge(v, u, w)); // 因为这里是儿子连边，不是老子连边
            if (++tot == n - 1) break;
        }
    }
}

void dfs(int u, int fa, int dis) {
    parent[0][u] = fa; w[0][u] = dis;
    for (int i = 1; (1 << i) <= depth[u]; ++i) parent[i][u] = parent[i - 1][parent[i - 1][u]], 
        w[i][u] = std::max(w[i - 1][u], w[i - 1][parent[i - 1][u]]);
    for (const auto &e : g[u]) if (e.v != fa) depth[e.v] = depth[u] + 1, dfs(e.v, u, e.w);
}

int lca(int u, int v) {
    int res = -100000000;
    if (depth[u] > depth[v]) std::swap(u, v);
    per(i, 20, 0) if (depth[u] <= depth[v] - (1 << i)) res = std::max(res, w[i][v]), v = parent[i][v];
    if (u == v) return res;
    per(i, 20, 0) if (parent[i][u] != parent[i][v]) 
        res = std::max(res, std::max(w[i][u], w[i][v])), u = parent[i][u], v = parent[i][v];
    return std::max(res, std::max(w[0][u], w[0][v]));
}

void solution() {
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read(), w = read();
        e[i] = Edge(u, v, w);
    }
    std::sort(e + 1, e + m + 1, [](const Edge &e1, const Edge &e2) { return e1.w < e2.w; });
    kruscal();
    dfs(1, 1, 0);
    Q = read();
    while (Q--) {
        int u = read(), v = read();
        if (find(u) != find(v)) puts("impossible");
        else print(lca(u, v)), puts("");
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
    logs("main.exe");
    solution();
}