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
    int v, w;
    Edge () {}
    Edge(int v, int w) : v(v), w(w) {}
    bool operator < (const Edge &rhs) const { return w > rhs.w; }
};

const int N = 1000 + 5;
int n, m, x, dis[N], dis1[N], dis2[N];
bool done[N];
std::vector<Edge> g[N];

void dijkstra1(int s) {
    std::priority_queue<Edge> pq; pq.push(Edge(s, 0)); memset(done, false, sizeof done); memset(dis, 0x3f, sizeof dis); dis[s] = 0; 
    while (!pq.empty()) {
        const Edge top = pq.top(); pq.pop(); int u = top.v; if (done[u]) continue; done[u] = true;
        for (const Edge &e : g[u]) { int v = e.v, w = e.w; if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, pq.push(Edge(v, dis[v])); }
    }
    rep(i, 1, n) dis1[i] = dis[i];
}

int dijkstra2(int s, int t) {
    std::priority_queue<Edge> pq; pq.push(Edge(s, 0)); memset(done, false, sizeof done); memset(dis, 0x3f, sizeof dis); dis[s] = 0; 
    while (!pq.empty()) {
        const Edge top = pq.top(); pq.pop(); int u = top.v; if (done[u]) continue; done[u] = true;
        for (const Edge &e : g[u]) { int v = e.v, w = e.w; if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, pq.push(Edge(v, dis[v])); }
    }
    return dis[t];
}

int calc(int u) {
    return dis1[u] + dijkstra2(u, x);
}

void solution() {
    n = read(), m = read(), x = read();
    while (m--) { int u = read(), v = read(), w = read(); g[u].push_back(Edge(v, w)); }
    dijkstra1(x); int ans = std::numeric_limits<int>::min(); rep(i, 1, n) ans = std::max(ans, calc(i)); println(ans);
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