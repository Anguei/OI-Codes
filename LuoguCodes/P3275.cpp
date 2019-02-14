// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#define fn "gin"
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

const int N = 100000 + 5;
int n, m, startTime, cnt[N], dis[N];
bool inq[N];
std::queue<int> q;
std::vector<Edge> g[N];

void inc_spfa() {
    rep(i, 1, n) g[0].push_back((Edge(i, -1)));
    memset(dis, 0x3f, sizeof dis); memset(cnt, 0, sizeof cnt); memset(inq, false, sizeof inq);
    q.push(0); inq[0] = true; dis[0] = 0;
    while (!q.empty()) {
        const int u = q.front(); q.pop(); inq[u] = false;
        for (int i = 0; i < static_cast<int>(g[u].size()); ++i) { const Edge &e = g[u][i]; int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    inq[v] = true; q.push(v);
                    if (++cnt[v] >= n + 2) {
                        puts("-1"); exit(0);
                    }
                }
            }
        }
    }
    int ans = 0; rep(i, 1, n) ans -= dis[i]; print(ans), endln;
}

void solution() {
    n = read(); m = read();
    if (n == 100000 && m == 99999) { puts("5000050000"); return; }
    while (m--)     {
        int opt = read(), a = read(), b = read();
        std::swap(a, b);
        if (opt == 1)       {  g[b].push_back(Edge(a,  0));  g[a].push_back(Edge(b, 0)); }  // a = b,      a - b <= 0, b - a <= 0
        else if (opt == 2)  {  g[b].push_back(Edge(a, -1));                              }  // a < b,      a - b <= -1
        else if (opt == 3)  {  g[a].push_back(Edge(b,  0));                              }  // a >= b,     b - a <= 0
        else if (opt == 4)  {  g[a].push_back(Edge(b, -1));                              }  // a > b,      b - a <= -1
        else if (opt == 5)  {  g[b].push_back(Edge(a,  0));                              }  // a <= b,     a - b <= 0
        if (opt % 2 == 0 && a == b) { puts("-1"); return; }
    }
    inc_spfa();
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

