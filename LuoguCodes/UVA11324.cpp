// 用于测试面包的 VSC 插件，写一下 UVA11324
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
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
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

const int N = 1000 + 5;
int n, m, dfsClock = 0, sccCnt = 0;
int dfn[N], low[N], color[N];
int size[N], mem[N];
bool ins[N];
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    stk.push(u); ins[u] = true;
    dfn[u] = low[u] = ++dfsClock;
    for (auto v : g[u]) {
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

int dp(int u) {
    if (mem[u]) return mem[u];
    int max = 0;
    for (auto v : dag[u]) max = std::max(max, dp(v));
    return max + size[u];
}

int solve() {
    dfsClock = sccCnt = 0;
    for (auto &i : g) i.clear(); for (auto &i : dag) i.clear();
    memset(ins, false, sizeof ins); memset(dfn, 0, sizeof dfn); memset(low, 0, sizeof low); memset(color, 0, sizeof color); memset(size, 0, sizeof size); memset(mem, 0, sizeof mem);
    while (!stk.empty()) stk.pop(); 

    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        if (u ^ v) g[u].push_back(v);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(i, 1, n) for (auto j : g[i]) if (color[i] ^ color[j]) dag[color[i]].push_back(color[j]);

    int ans = 0;
    rep(i, 1, sccCnt) ans = std::max(ans, dp(i));
    return print(ans), puts(""), 0;
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
    freopen("testdata.out", "w", stdout);
#endif
    int T = read(); while (T--) solve();
}