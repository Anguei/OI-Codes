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
#define dbg2(x, y) std::clog << #x" = " << (x) << ", "#y" = " << (y) << std::endl
#else
#define dbg(x) x
#define dbg2(x, y) x, y
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

const int N = 20000 + 5;
int n, m, dfsClock, sccCnt;
int dfn[N], low[N], color[N], size[N];
bool ins[N], ind[N], outd[N];
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    ins[u] = true; stk.push(u);
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

int solve() {
    for (auto &i : g) i.clear(); for (auto &i : dag) i.clear();
    dfsClock = sccCnt = 0;
    //rep(i, 0, N - 1) g[i].clear(); rep(i, 0, N - 1) dag[i].clear();
    while (!stk.empty()) stk.pop();
    memset(ins, false, sizeof ins); memset(low, 0, sizeof low); memset(dfn, 0, sizeof dfn); memset(color, 0, sizeof color); memset(size, 0, sizeof size);
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        g[u].push_back(v);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    if (sccCnt == 1) return 0;
    rep(i, 1, sccCnt) ind[i] = outd[i] = true;
    rep(u, 1, n) for (const auto &v : g[u]) if (color[u] != color[v]) outd[color[u]] = ind[color[v]] = false;
    int ans1 = 0, ans2 = 0;
    rep(i, 1, sccCnt) {
        if (ind[i]) ++ans1;
        if (outd[i]) ++ans2;
    }
    //dbg(sccCnt);
    //dbg2(ans1, ans2);
    return std::max(ans1, ans2);
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
    freopen("testdata.out", "w", stdout);
#endif
    int T = read(); while (T--) print(solve()), puts("");
}