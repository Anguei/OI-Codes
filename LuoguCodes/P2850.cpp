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
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
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

struct Edge {
    int v, w;
    Edge() {}
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 500 + 5;
int n, m, W, cnt[N], dis[N];
bool ok, vis[N];
std::queue<Edge> q;
std::vector<Edge> g[N];

void spfa(int u) {
    vis[u] = true;
    for (const auto &e : g[u]) { int v = e.v, w = e.w; if (dis[v] > dis[u] + w)
        if (vis[v]) { ok = true; return; }
        else dis[v] = dis[u] + w, spfa(v);
    }
    vis[u] = false;
}

void solution() {
    ok = false; rep(i, 1, N - 1) g[i].clear(); memset(cnt, 0, sizeof cnt); memset(vis, false, sizeof vis); memset(dis, 0, sizeof dis);
    n = read(), m = read(), W = read();
    while (m--) { int u = read(), v = read(), w = read(); g[u].push_back(Edge(v, w)); g[v].push_back(Edge(u, w)); }
    while (W--) { int u = read(), v = read(), w = -read(); g[u].push_back(Edge(v, w)); }
    rep(i, 1, n) { spfa(i); if (ok) break; } puts(ok ? "YES" : "NO");
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
    int T = read(); while (T--) solution();
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}