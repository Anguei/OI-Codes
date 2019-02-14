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
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
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

const int N = 500000 + 5;
int n, m, s, p, dfsClock = 0, sccCnt = 0, ans = 0;
int low[N], dfn[N], size[N], color[N], a[N], dis[N];
bool ins[N], inq[N];
std::queue<int> q;
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); else if (ins[v]) low[u] = std::min(low[u], dfn[v]); // sillyBug: if (dfn[v]) ...
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            size[sccCnt] += a[u];
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

void spfa() {
    //memset(dis, 0xc0, sizeof dis);
    dis[s] = size[s]; q.push(s); inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (const auto &v : dag[u]) {
            //const auto &v = e.v;
            if (dis[v] < dis[u] + size[v]) {
                dbg(v);
                dis[v] = dis[u] + size[v];
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
#endif
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        g[u].push_back(v);
    }
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(i, 1, sccCnt) dbg(size[i]);
    rep(u, 1, n) for (const auto &v : g[u]) if (color[u] != color[v]) dag[color[u]].push_back(color[v]);
    s = read(); s = color[s]; p = read();
    spfa();
    rep(i, 1, p) ans = std::max(ans, dis[color[read()]]); // sillyBug: ans = std::max(ans, dis[read()]);
    print(ans), puts("");
}