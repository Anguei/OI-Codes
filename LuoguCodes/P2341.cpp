// 测试面包的 VSC 插件，写 P2341。
// DAG 中，从任意一个点出发，必定可以到达某个出度为零的点。
// 当且仅当只有一个出度为零的点时，此题有解，为该 scc 大小。
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

const int N = 10000 + 5;
int dfsClock = 0, sccCnt = 0;
int low[N], dfn[N], color[N], size[N], outd[N];
bool ins[N];
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    stk.push(u); ins[u] = true;
    low[u] = dfn[u] = ++dfsClock;
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
        } while (low[u] ^ dfn[u]);
    }
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
#endif
    int n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        g[u].push_back(v);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(i, 1, n) for (auto j : g[i]) if (color[i] ^ color[j]) dag[color[i]].push_back(color[j]), ++outd[color[i]];
    int cnt = 0, id = 0, ans = 0;
    rep(i, 1, sccCnt) if (outd[i] == 0) ++cnt, id = i;
    if (cnt != 1) return puts("0"), 0;
    print(size[id]), puts("");
}