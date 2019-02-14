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
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define add(u, v) e[++cnt] = Edge(v, head[u]), head[u] = cnt
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
    int v, next;
    Edge() {}
    Edge(int v, int next) : v(v), next(next) {}
};

const int N = 100 + 5;
int n, cnt = 0, ans = 0x7fffffff, a[N], head[N], depth[N], parent[11][N];
Edge e[N << 1];

void dfs(int u, int fa) {
    dbg(u);
    parent[0][u] = fa;
    for (int i = 1; (1 << i) <= depth[u]; ++i) parent[i][u] = parent[i - 1][parent[i - 1][u]];
    for (int i = head[u]; i; i = e[i].next) if (e[i].v != fa) depth[e[i].v] = depth[u] + 1, dfs(e[i].v, u);
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    per(i, 10, 0) if (depth[u] <= depth[v] - (1 << i)) v = parent[i][v]; if (u == v) return u;
    per(i, 10, 0) if (parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v]; return parent[0][u];
}

int dis(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

void solution() {
    n = read(); rep(i, 1, n) { a[i] = read(); int ls = read(), rs = read(); if (ls) add(i, ls), add(ls, i); if (rs) add(i, rs), add(rs, i); } dfs(1, -1);
    rep(i, 1, n) { dbg(i); int tot = 0; rep(j, 1, n) if (j != i) tot += dis(i, j) * a[j]; ans = std::min(ans, tot); } println(ans);
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