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

struct Edge { int v, w; Edge () {} Edge(int v, int w) : v(v), w(w) {} };
struct HeapNode { int u, l, d; HeapNode() {} HeapNode(int u, int l, int d) : u(u), l(l), d(d) {} bool operator < (const HeapNode &rhs) const { return d > rhs.d; } };

const int N = 1000 + 5, M = 100 + 5; int n, m, Q, p[N]; std::vector<Edge> g[N]; int dis[N][M]; bool done[N][M]; std::priority_queue<HeapNode> pq;

int dijkstra(int s, int e, int c) {
    memset(dis, 0x3f, sizeof dis); memset(done, false, sizeof done); dis[s][0] = 0; pq.push(HeapNode(s, 0, 0)); while (!pq.empty()) {
        const auto top = pq.top(); pq.pop(); int u = top.u, l = top.l; if (done[u][l]) continue; done[u][l] = true;
        for (const auto &e : g[u]) { int v = e.v, w = e.w; if (w > l) continue; if (dis[v][l - w] > dis[u][l]) dis[v][l - w] = dis[u][l], pq.push(HeapNode(v, l - w, dis[v][l - w])); }
        if (l < c && dis[u][l + 1] > dis[u][l] + p[u]) dis[u][l + 1] = dis[u][l] + p[u], pq.push(HeapNode(u, l + 1, dis[u][l + 1])); 
    } return dis[e][0];
}

void solution() {
    n = read(), m = read(); rep(i, 0, n - 1) p[i] = read(); while (m--) { int u = read(), v = read(), w = read(); g[u].push_back(Edge(v, w)); g[v].push_back(Edge(u, w)); }
    Q = read(); while (Q--) { int c = read(), s = read(), e = read(); int ans = dijkstra(s, e, c); if (ans == 0x3f3f3f3f3f3f3f3f) puts("impossible"); else println(ans); }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}