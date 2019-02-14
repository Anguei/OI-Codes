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
#define fn "task"
#define ll long long
// #define int long long
#define pc(x) putchar(x)
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

const int N = 1000 + 5;
int n, ml, md, dis[N], circle[N];
bool inq[N];
std::vector<Edge> g[N];
std::queue<Edge> q;

void spfa(int s) {
    memset(inq, 0, sizeof inq);
    memset(dis, 0x3f, sizeof dis);
    memset(circle, 0, sizeof circle);

    q.push(Edge(s, 0)); inq[s] = true; dis[s] = 0;
    while (!q.empty()) {
        Edge front = q.front(); int u = front.v; q.pop(); inq[u] = false;
        for (int i = 0; i < g[u].size(); ++i) {
            Edge e = g[u][i];
            if (dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                if ((circle[e.v] = circle[u] + 1) >= n) {
                    puts("-1"); exit(0);
                }
                if (!inq[e.v]) {
                    q.push(Edge(e.v, dis[e.v]));
                    inq[e.v] = true;
                }
            }
        }
    }
}

void solution() {
    n = read(), ml = read(), md = read();
    rep(i, 1, n) g[0].push_back(Edge(i, 0));
    while (ml--) {
        int a = read(), b = read(), d = read();
        g[a].push_back(Edge(b, d));
    }
    while (md--) {
        int a = read(), b = read(), d = read();
        g[b].push_back(Edge(a, -d));
    }
    spfa(0); spfa(1);
    print(dis[n] == 0x3f3f3f3f ? -2 : dis[n]); puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}