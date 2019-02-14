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
    Edge() {}
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 30000 + 5, H = 5000 + 5;
int n, h, dis[N];
bool inq[N];
std::queue<int> q;
std::vector<Edge> g[N];

void spfa(int s = 0) {
    memset(dis, 0x3f, sizeof dis); q.push(s); inq[s] = true; dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (const auto &e : g[u]) { int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
    int min = -1ull / 2; rep(i, 0, n + 1) min = std::min(min, dis[i]);
    println(dis[n] - min);
#ifdef yyfLocal
    rep(i, 0, n + 1) std::clog << i << " " << dis[i] << std::endl;
#endif
}

void solution() {
    n = read(), h = read();
    rep(i, 1, h) {
        int b = read(), e = read(), t = read();
        g[e].push_back(Edge(b - 1, -t));
    }
    rep(i, 0, n) g[n + 1].push_back(Edge(i, 0));
    rep(i, 1, n) g[i - 1].push_back(Edge(i, 1)), g[i].push_back(Edge(i - 1, 0));
    // rep(i, 0, n + 1) std::clog << i << " " << g[i].size() << std::endl;
    spfa(n + 1);
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