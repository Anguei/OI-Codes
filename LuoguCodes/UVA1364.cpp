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
#define clog(x) std::clog << (x) << std::endl;
#else
#define dbg(x) 42
#define clog(x) 42
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
    int u, v;
    Edge() = default;
    Edge(int u, int v) : u(u), v(v) {}
};

const int N = 1000 + 5;
int n, m, ans, dfsClock = 0, bccCnt = 0, bccNo[N], dfn[N], low[N], color[N];
bool cut[N], map[N][N], odd[N];
std::vector<int> g[N], bcc[N];
std::stack<Edge> stk;

void clear() {
    bccCnt = dfsClock = 0;
    rep(i, 1, n) g[i].clear();
    rep(i, 1, n) bcc[i].clear();
    memset(odd, 0, sizeof odd);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(bccNo, 0, sizeof bccNo);
    memset(cut, false, sizeof cut);
    memset(map, false, sizeof map);
}

void init() {
    while (m--) {
        int u = read(), v = read();
        map[u][v] = map[v][u] = true;
    }
    rep(u, 1, n) rep(v, u + 1, n) if (!map[u][v]) g[u].push_back(v), g[v].push_back(u);
}

/*void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++dfsClock;
    int child = 0;
    for (const auto &v : g[u]) {
        if (!dfn[v]) {
            stk.push(Edge(u, v));
            tarjan(v, fa);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= low[u] && u != fa) {
                ++bccCnt;
                cut[u] = true;
                while (true) {
                    if (stk.empty()) break;
                    Edge x = stk.top(); stk.pop();
                    if (bccNo[x.u] != bccCnt) bcc[bccCnt].push_back(x.u), bccNo[x.u] = bccCnt;
                    if (bccNo[x.v] != bccCnt) bcc[bccCnt].push_back(x.v), bccNo[x.v] = bccCnt;
                    clog("added");
                    if (x.u == x.v || stk.empty()) break;
                }
            }
            if (u == fa) ++child;
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (child >= 2 && u == fa) {
        clog("more than 2 children");
        ++bccCnt;
        cut[u] = true;
        while (true) {
            if (stk.empty()) break;
            Edge x = stk.top(); stk.pop();
            if (bccNo[x.u] != bccCnt) bcc[bccCnt].push_back(x.u), bccNo[x.u] = bccCnt;
            if (bccNo[x.v] != bccCnt) bcc[bccCnt].push_back(x.v), bccNo[x.v] = bccCnt;
            if (x.u == x.v || stk.empty()) break;
        }
    }
}*/

int tarjan(int u, int fa) { // 根据刘汝佳蓝书上的 Tarjan 算法改写一下。
    low[u] = dfn[u] = ++dfsClock;
    int child = 0;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        Edge e = Edge(u, v);
        if(!dfn[v]) {
            stk.push(e);
            child++;
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                cut[u] = true;
                ++bccCnt;
                while (true) {
                    Edge x = stk.top(); stk.pop();
                    if(bccNo[x.u] != bccCnt) bcc[bccCnt].push_back(x.u), bccNo[x.u] = bccCnt;
                    if(bccNo[x.v] != bccCnt) bcc[bccCnt].push_back(x.v), bccNo[x.v] = bccCnt;
                    if(x.u == u && x.v == v) break;
                }
            }
        }
        else if(dfn[v] < dfn[u] && v != fa) {
            stk.push(e);
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(fa < 0 && child == 1) cut[u] = 0;
    return low[u];
}

void findBcc() {
    rep(i, 1, n) if (!dfn[i]) tarjan(i, i); // , dbg(i);
}

bool bipartite(int u, int b) {
    for (int i = 0; i < g[u].size(); ++i) {
        // dbg(i);
        int v = g[u][i];
        if (bccNo[v] != b) continue;
        if (color[v] == color[u]) return false;
        if (!color[v]) {
            color[v] = 3 - color[u];
            if (!bipartite(v, b)) return false;
        }
    }
    return true;
}

void output() {
    // dbg(bccCnt);
    rep(i, 1, bccCnt) {
        // dbg(i);
        memset(color, 0, sizeof color);
        for (int j = 0; j < bcc[i].size(); ++j) bccNo[bcc[i][j]] = i;
        int u = bcc[i][0];
        color[u] = 1;
        if (!bipartite(u, i)) {
            // clog("bipartited");
            for (int j = 0; j < bcc[i].size(); ++j) odd[bcc[i][j]] = true;
        }
    }
    ans = n;
    rep(i, 1, n) ans -= odd[i];
    print(ans), puts("");
}

void solution() {
    clear();
    // clog("cleared");
    init();
    // clog("inited");
    findBcc();
    // clog("findBcced");
    output();
    // clog("outputed");
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
    while (std::cin >> n >> m && n + m) solution();
}