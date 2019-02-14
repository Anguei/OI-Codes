// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 老婆的插件提交 P2656
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

struct Edge {
    int v, w;
    double k;
    Edge() = default;
    Edge(int _v, int _w, double _k) : v(_v), w(_w), k(_k) {}
    bool operator < (const Edge &rhs) const {
        return w > rhs.w;
    }
};

const int N = 80000;
int n, m, s, dfsClock = 0, sccCnt = 0, ans = 0;
int low[N], dfn[N], color[N], size[N], sum[N], dis[N];
bool ins[N], inq[N];
std::queue<int> q;
std::stack<int> stk;
std::vector<Edge> g[N], dag[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const auto &e: g[u]) if (!dfn[e.v]) tarjan(e.v), low[u] = std::min(low[u], low[e.v]); else if (ins[e.v]) low[u] = std::min(low[u], dfn[e.v]);
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            ++size[sccCnt];
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

void spfa() {
    memset(dis, -1, sizeof dis);
    q.push(s); inq[s] = true; dis[s] = sum[s];
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (const auto &e : dag[u]) {
            const auto &v = e.v;
            if (dis[v] < dis[u] + e.w) {
                dis[v] = dis[u] + e.w;
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
#endif
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read(), w = read(); 
        double k; std::cin >> k;
        g[u].push_back(Edge(v, w, k));
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(u, 1, n) for (const auto &e : g[u]) {
        const auto &v = e.v;
        if (color[u] == color[v]) {
            int tmp = e.w;
            while (tmp) {
                sum[color[v]] += tmp; // sillyBug: sum[v] += tmp;
                tmp *= e.k;
            }
        } else dag[color[u]].push_back(Edge(color[v], e.w, e.k));
    }
    s = color[read()];
    spfa();
    rep(i, 1, sccCnt) ans = std::max(ans, dis[i]);
    print(ans), puts("");
}