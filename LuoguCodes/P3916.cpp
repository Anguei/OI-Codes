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

const int N = 100000 + 5;
int n, m, sccCnt = 0, dfsClock = 0, low[N], dfn[N], color[N], size[N], val[N], ans[N];
bool ins[N], vis[N];
std::vector<int> g[N], dag[N];
std::stack<int> stk;

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) {
        if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            ++size[sccCnt];
            val[sccCnt] = std::max(val[sccCnt], u);
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    ans[u] = val[u];
    for (const auto &v : dag[u]) dfs(v), ans[u] = std::max(ans[u], ans[v]);
}

void solution() {
    n = read(), m = read();
    while (m--) {
        int u = read(), v = read();
        g[u].push_back(v);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(u, 1, n) for (const auto &v : g[u]) if (color[u] != color[v]) dag[color[u]].push_back(color[v]);
    rep(i, 1, n) if (!vis[i]) dfs(i);
    rep(i, 1, n) print(ans[color[i]]), pc('; ';);

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