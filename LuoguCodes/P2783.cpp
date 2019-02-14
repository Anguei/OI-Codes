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
// #define int long long
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

const int N = 10000 + 5;
int bccCnt = 0, dfsClock = 0, n, m, low[N], dfn[N], color[N], size[N], parent[25][N], depth[N];
bool ins[N];
std::vector<int> g[N], dag[N];
std::stack<int> stk;

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) {
        if (v != fa) {
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
            } else if (ins[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    }
    if (low[u] == dfn[u]) {
        ++bccCnt;
        do {
            color[u] = bccCnt;
            ++size[bccCnt];
            u = stk.top(); stk.pop(); ins[u] = false;
        } while(low[u] != dfn[u]);
    }
}

void input() {
    n = read(), m = read();
    while (m--) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void bcc() {
    rep(i, 1, n) if (!dfn[i]) tarjan(i, 0);
    rep(i, 1, n) for (const auto &j : g[i]) if (color[i] != color[j]) dag[color[i]].push_back(color[j]);
}

void dfs(int u, int fa) {
    parent[0][u] = fa;
    for (int i = 1; (1 << i) <= depth[u]; ++i) parent[i][u] = parent[i - 1][parent[i - 1][u]];
    for (const auto &v : dag[u]) if (v != fa) depth[v] = depth[u] + 1, dfs(v, u);
}

void initLca() {
    dfs(1, 1);
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    per(i, 20, 0) if (depth[u] <= depth[v] - (1 << i)) v = parent[i][v];
    if (u == v) return u;
    per(i, 20, 0) if (parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v];
    return parent[0][u];
}

std::string toBin(int x) {
    std::string res = "";
    while (x) {
        res += (x & 1) + 48;
        x >>= 1;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

void answer() {
    int q = read();
    while (q--) {
        int u = read(), v = read();
        int ans = depth[color[u]] + depth[color[v]] - (depth[lca(color[u], color[v])] << 1) + 1;
        puts(toBin(ans).data());
    }
}

void solution() {
    input();
    bcc();
    initLca();
    answer();
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