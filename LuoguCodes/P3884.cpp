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
    int v, next;
    Edge() = default;
    Edge(int v, int next) : v(v), next(next) {}
};

const int N = 100 + 5;
int n, u, v, cnt = 0, depth[N], parent[10][N], head[N];
Edge e[N << 1];

void add(int u, int v) {
    e[++cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

void dfs(int u, int fa) {
    parent[0][u] = fa;
    for (int i = 1; (1 << i) <= depth[u]; ++i) {
        parent[i][u] = parent[i - 1][parent[i - 1][u]];
    }
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v != fa) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    per(i, 9, 0) {
        if (depth[u] <= depth[v] - (1 << i)) {
            v = parent[i][v];
        }
    }
    if (u == v) return u;
    per(i, 9, 0) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

void DEP() {
    dfs(1, 1);
    int max = 0;
    rep(i, 1, n) max = std::max(max, depth[i]);
    print(max + 1), puts("");
}

void WEI() {
    int max = 0;
    std::map<int, int> map;
    rep(i, 1, n) ++map[depth[i]];
    for (const auto &i : map) max = std::max(max, i.second);
    print(max), puts("");
}

void DIS() {
    int tmp = lca(u, v);
    print(((depth[u] - depth[tmp]) << 1) + depth[v] - depth[tmp]), puts("");
}

void solution() {
    n = read();
    rep(i, 2, n) {
        int u = read(), v = read();
        add(u, v); add(v, u);
    }
    u = read(), v = read();
    DEP(); WEI(); DIS();
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