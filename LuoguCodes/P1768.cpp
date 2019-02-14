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
#define println(x) print(x), endln
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
    int v, w, q;
    Edge() {}
    Edge(int v, int q, int w) : v(v), q(q), w(w) {}
};

const int N = 7000 + 5;
int n, m;
double dis[N];
bool vis[N];
std::vector<Edge> g[N];

bool spfa(double mid, int u) {
    vis[u] = true;
    for (const auto &e : g[u]) { int v = e.v, q = e.q; double w = static_cast<double>(e.w) * mid - q;
        if (dis[v] > dis[u] + w) {
            if (vis[v]) return true;
            dis[v] = dis[u] + w; vis[v] = true;
            if (spfa(mid, v)) return true;
        }
    }
    vis[u] = false;
    return false;
}

bool check(double mid) {
    memset(vis, false, sizeof vis); std::fill(dis + 1, dis + n + 1, 1e10);
    return spfa(mid, 0);
}

void solution() {
    n = read(), m = read();
    while (m--) {
        int u = read(), v = read(), q = read(), w = read();
        g[u].push_back(Edge(v, q, w));
    }
    rep(i, 0, n) g[0].push_back(Edge(i, 0, 0));
    double l = 0, r = 200; int eft = 15; while (eft--) {
        double mid = (l + r) / 2; if (check(mid)) l = mid; else r = mid;
    }
    if (l == 0) puts("-1"); else std::cout << std::fixed << std::setprecision(1) << l << std::endl;
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