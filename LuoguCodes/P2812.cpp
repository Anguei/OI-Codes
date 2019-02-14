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
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)
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
int dfsClock = 0, sccCnt = 0, ans1 = 0, ans2 = 0, tmp;
int dfn[N], low[N], color[N], size[N], outd[N], ind[N];
bool ins[N];
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    ins[u] = true; stk.push(u);
    //for (const auto &v : g[u]) if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    for (int i = 0; i < g[u].size(); ++i) if (!dfn[g[u][i]]) tarjan(g[u][i]), low[u] = std::min(low[u], low[g[u][i]]); else if (ins[g[u][i]]) low[u] = std::min(low[u], dfn[g[u][i]]);
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            ++size[sccCnt];
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
#endif
    int n = read();
    rep(i, 1, n) while (tmp = read()) g[i].push_back(tmp);
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    //rep(i, 1, n) for (const auto &j : g[i]) if (color[i] != color[j]) dag[color[i]].push_back(color[j]), ++outd[color[i]], ++ind[color[j]];
    rep(i, 1, n) for (int j = 0; j < g[i].size(); ++j) if (color[i] != color[g[i][j]]) dag[color[i]].push_back(color[g[i][j]]), ++outd[color[i]], ++ind[color[g[i][j]]];
    rep(i, 1, sccCnt) if (ind[i] == 0) ++ans1; rep(i, 1, sccCnt) if (outd[i] == 0) ++ans2;
    if (sccCnt == 1) puts("1\n0"); else print(ans1), puts(""), print(std::max(ans1, ans2)), puts("");
}