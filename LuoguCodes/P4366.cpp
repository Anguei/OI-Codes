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
#define fn "6354"
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

namespace Vector {
    struct Edge {
        int v, w;
        Edge() {}
        Edge(int v, int w) : v(v), w(w) {}
        bool operator < (const Edge &rhs) const { return w > rhs.w; }
    };

    const int N = 1000000 + 5;
    int n, m, c, limit, dis[N];
    bool done[N];
    std::vector<Edge> g[N];
    std::priority_queue<Edge> pq;

    #undef add
    #define add(u, v, w) g[(u)].push_back(Edge((v), (w)))

    int dijkstra(int s, int t) {
        memset(dis, 0x3f, sizeof dis); memset(done, 0, sizeof done); dis[s] = 0; pq.push(Edge(s, 0));
        while (!pq.empty()) { const Edge top = pq.top(); pq.pop(); int u = top.v; if (done[u]) continue; done[u] = true;
            for (const auto &e : g[u]) { int v = e.v, w = e.w; if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; pq.push(Edge(v, dis[v])); } }
            for (int i = 0; i <= limit; ++i) { int v = u ^ (1 << i), w = c * (1 << i); if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; pq.push(Edge(v, dis[v])); } }
        }
        return dis[t];
    }

    void solution() {
        n = read(), m = read(), c = read(); limit = static_cast<int>(log2(n));
        while (m--) { int u = read(), v = read(), w = read(); add(u, v, w); }
        int s = read(), t = read(); println(dijkstra(s, t));
    }
}

namespace List {
    struct Edge {
        int v, w, next;
        Edge() {}
        Edge(int v, int w, int next) : v(v), w(w), next(next) {}
    };

    struct Node {
        int v, w;
        Node() {}
        Node(int v, int w) : v(v), w(w) {}
        bool operator < (const Node &rhs) const { return w > rhs.w; }
    };

    const int N = 1000000 + 5, M = 500000 + 5;
    int n, m, c, limit, cnt = 0, head[N], dis[N];
    bool done[N];
    Edge e[M];
    std::priority_queue<Node> pq;

    #undef add
    #define add(u, v, w) e[++cnt] = Edge(v, w, head[u]), head[u] = cnt

    int dijkstra(int s, int t) {
        memset(dis, 0x3f, sizeof dis); memset(done, 0, sizeof done); dis[s] = 0; pq.push(Node(s, 0));
        while (!pq.empty()) { const Node top = pq.top(); pq.pop(); int u = top.v; if (done[u]) continue; done[u] = true;
            for (int i = head[u]; i; i = e[i].next) { int v = e[i].v, w = e[i].w; if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; pq.push(Node(v, dis[v])); } }
            for (int i = 0; i <= limit; ++i) { int v = u ^ (1 << i), w = c * (1 << i); if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; pq.push(Node(v, dis[v])); } }
        }
        return dis[t];
    }

    void solution() {
        n = read(), m = read(), c = read(); limit = static_cast<int>(log2(n));
        while (m--) { int u = read(), v = read(), w = read(); add(u, v, w); }
        int s = read(), t = read(); println(dijkstra(s, t));
    }
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
    List::solution();
    // Vector::solution();
}