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
#define fn "2427"
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

const int N = 100 + 5, M = 500 + 5;
int n, m, sccCnt = 0, dfsClock = 0, w[N], v[N], d[N], low[N], dfn[N], color[N], size[N], V[N], W[N], ind[N], dp[N][M];
bool ins[N];
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
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

void dfs(int u) {
    rep(i, W[u], m) dp[u][i] += V[u];
    for (const auto &v : dag[u]) {
        dfs(v);
        per(j, m - W[u], 0) rep(k, 0, j) dp[u][j + W[u]] = std::max(dp[u][j + W[u]], dp[u][j + W[u] - k] + dp[v][k]);
    }
}

void solution() {
    n = read(), m = read();
    rep(i, 1, n) w[i] = read();
    rep(i, 1, n) v[i] = read();
    rep(i, 1, n) d[i] = read();
    rep(i, 1, n) if (d[i]) g[d[i]].push_back(i);
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(i, 1, n) V[color[i]] += v[i], W[color[i]] += w[i];
    rep(i, 1, n) if (color[i] != color[d[i]] && color[d[i]]) dag[color[d[i]]].push_back(color[i]), ++ind[color[i]];
    rep(i, 1, sccCnt) if (!ind[i]) dag[sccCnt + 1].push_back(i);
    dfs(sccCnt + 1); print(dp[sccCnt + 1][m]), puts("");
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