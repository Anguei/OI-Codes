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
#else
#define dbg(x) x
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
    int v, next;
    Edge() = default;
    Edge(int v, int next) : v(v), next(next) {}
};

const int N = 100000 + 5;
int n, q, cnt = 0, head[N << 1], depth[N], parent[25][N];
Edge e[N << 1];

void add(int u, int v) {
    e[++cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

void dfs(int u, int fa) {
    parent[0][u] = fa;
    for (int i = 1; (1 << i) <= depth[u]; ++i) parent[i][u] = parent[i - 1][parent[i - 1][u]];
    for (int i = head[u]; i; i = e[i].next) if (e[i].v != fa) depth[e[i].v] = depth[u] + 1, dfs(e[i].v, u);
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    per(i, 20, 0) if (depth[u] <= depth[v] - (1 << i)) v = parent[i][v];
    if (u == v) return u;
    per(i, 20, 0) if (parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v];
    return parent[0][u];
}

void solution() {
    n = read(), q = read();
    rep(i, 2, n) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    while (q--) {
        int a = read(), b = read(), c = read(), d = read();
        int A = lca(a, b), B = lca(c, d);
        if (depth[A] < depth[B]) std::swap(A, B), std::swap(a, c), std::swap(b, d);
        puts(lca(A, c) == A || lca(A, d) == A ? "Y" : "N");
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}