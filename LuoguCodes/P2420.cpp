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
    int v, w;
    Edge() = default;
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 100000 + 5;
int n, q;
int depth[N], xorSum[N], parent[20][N];
std::vector<Edge> g[N];

void dfs(int u, int fa, int XOR) {
    xorSum[u] = XOR;
    for (const auto &e : g[u]) {
        int v = e.v;
        if (v != fa) {
            dfs(v, u, XOR ^ e.w);
            depth[v] = depth[u] + 1;
        }
    }
}

void solution() {
    n = read();
    rep(i, 2, n) {
        int u = read(), v = read(), w = read();
        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
    }
    q = read();
    depth[1] = 1; dfs(1, 1, 1);
    while (q--) {
        int u = read(), v = read();
        // int tmp = lca(u, v); 两次异或消除掉了
        print(xorSum[u] ^ xorSum[v]), puts("");
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