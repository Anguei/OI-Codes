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
#define add(u, v, w) e[++cnt] = Edge(v, w, head[u]), head[u] = cnt
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

struct Edge{
    int v, w, next;
    Edge() {}
    Edge(int v, int w, int next) : v(v), w(w), next(next) {}
};

struct Node {
    int v, w;
    Node() {}
    Node(int v, int w) : v(v), w(w) {}
    bool operator<(const Node &rhs) const { return w > rhs.w; }
};

const int N = 10000 + 5, M = 50000 * 2 + 5;
int head[N], cnt, a[N], n, m, b, bBak, dis[N];
bool done[N];
Edge e[M];
std::priority_queue<Node> pq;

bool dijkstra(int s, int t, int mid = 0x7fffffff) {
    if (a[s] > mid || a[t] > mid) return false; memset(dis, 0x3f, sizeof dis); memset(done, false, sizeof done); dis[s] = 0; pq.push(Node(s, 0)); while (!pq.empty()) {
        int u = pq.top().v; pq.pop(); if (done[u]) continue; done[u] = true;
        for (int i = head[u]; i; i = e[i].next) if (dis[e[i].v] > dis[u] + e[i].w && a[e[i].v] <= mid) dis[e[i].v] = dis[u] + e[i].w, pq.push(Node(e[i].v, dis[e[i].v]));
    } dbg(b); return b > dis[t];
}
bool check(int mid) { b = bBak; dbg(b); return dijkstra(1, n, mid); }

void solution() {
    n = read(), m = read(), bBak = b = read(); rep(i, 1, n) a[i] = read(); rep(i, 1, m) { int u = read(), v = read(), w = read(); add(u, v, w), add(v, u, w); }
    if (!dijkstra(1, n)) { puts("AFK"); return; } logs("efing"); int l = 0, r = *std::max_element(a + 1, a + n + 1); while (l < r) { int mid = (l + r) >> 1; if (check(mid)) r = mid; else l = mid + 1; } println(l);
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