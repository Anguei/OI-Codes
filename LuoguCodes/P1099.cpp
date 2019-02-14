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
#define fn "2282"
#define ll long long
// #define int long long
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
    Edge() {}
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 500000 + 5;
std::vector<Edge> g[N];
int n, m, root, head, tail, dis[N], w[N], from[N], b[N], a[N], c[N], f[N], fl[N], fr[N];
std::pair<int, int> q2[N];

std::queue<int> q;
void bfs(int s) {
    memset(dis, -1, sizeof dis); dis[s] = 0; q.push(s); from[s] = 0; w[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int it = 0; it < static_cast<int>(g[u].size()); ++it) { const Edge &e = g[u][it]; int v = e.v, W = e.w;
            if (dis[v] == -1) {
                dis[v] = dis[u] + W;
                w[v] = W; from[v] = u;
                q.push(v);
            }
        }
    }
}

void dfs(int u, int fa, int depth, int &s) {
    s = std::max(s, depth);
    for (int it = 0; it < static_cast<int>(g[u].size()); ++it) { const Edge &e = g[u][it]; if (!b[e.v] && e.v != fa) dfs(e.v, u, depth + e.w, s); }
}

void add(int x) {
    while (tail >= head && q2[tail].second <= f[x]) --tail; q2[++tail] = std::make_pair(x, f[x]);
}

void del(int x) {
    if (q2[head].first == x) ++head;
}

void solution() {    
    n = read(), m = read();
    rep(i, 2, n) {
        int u = read(), v = read(), w = read();
        g[u].push_back(Edge(v, w)); g[v].push_back(Edge(u, w));
    }
    bfs(1); root = 1; rep(i, 1, n) if (dis[i] > dis[root]) root = i;
    bfs(root); rep(i, 1, n) if (dis[i] > dis[root]) root = i;
    int t = 0; do {
        a[++t] = root; c[t] = w[root]; root = from[root];
    } while (root);
    rep(i, 1, t) b[a[i]] = 1;
    rep(i, 1, t) for (int it = 0; it < static_cast<int>(g[a[i]].size()); ++it) { const Edge &e = g[a[i]][it]; if (!b[e.v]) dfs(e.v, 0, e.w, f[i]); }
    rep(i, 1, t) fl[i] = std::max(f[i], fl[i - 1] + c[i - 1]);
    per(i, t, 1) fr[i] = std::max(f[i], fr[i + 1] + c[i]);
    rep(i, 1, t) c[i] += c[i - 1];
    head = 1, tail = 0; int ans = 1e9, j = 1;
    rep(i, 1, t) {
        add(i); while (c[i - 1] - c[j - 1] > m) del(j++);
        ans = std::min(ans, std::max(std::max(fl[j], fr[i]), q2[head].second));
    }
    println(ans);
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