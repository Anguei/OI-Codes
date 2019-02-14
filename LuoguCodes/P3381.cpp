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
    int v, w, f, next;
    Edge() = default;
    Edge(int v, int w, int f, int next) : v(v), w(w), f(f), next(next) {}
};

const int N = 5000 + 5, M = 50000 + 5;
int n, m, s, t, ecnt, head[N];
Edge e[M << 1];

inline void adde(int u, int v, int w, int f) {
    e[++ecnt] = Edge(v, w, f, head[u]);
    head[u] = ecnt;
}

namespace EdmondsKarp {
    struct Pre {
        int v, e;
        Pre() = default;
        Pre(int v, int e) : v(v), e(e) {}
    } pre[M];
    int dis[N]; bool inq[N]; std::queue<int> q;

    bool spfa() {
        memset(dis, 0x3f, sizeof dis); memset(inq, false, sizeof inq);
        q.push(s), inq[s] = true, dis[s] = 0; while (!q.empty()) {
            int u = q.front(); q.pop(); inq[u] = false; for (int i = head[u]; i; i = e[i].next) {
                int v = e[i].v, w = e[i].w, f = e[i].f; if (w && dis[v] > dis[u] + f) {
                    dis[v] = dis[u] + f; pre[v] = Pre(u, i);
                    if (!inq[v]) inq[v] = true, q.push(v);
                }
            }
        } return dis[t] != 0x3f3f3f3f;
    }

    void EK() {
        int ans = 0, bns = 0; while (spfa()) {
            int min = -1u / 2;
            for (int i = t; i != s; i = pre[i].v) min = std::min(min, e[pre[i].e].w);
            for (int i = t; i != s; i = pre[i].v) e[pre[i].e].w -= min, e[pre[i].e ^ 1].w += min;
            ans += min; bns += min * dis[t];
        } print(ans), pc('; ';), println(bns);
    }

    void solution() {
        ecnt = 1; n = read(), m = read(), s = read(), t = read();
        while (m--) {
            int u = read(), v = read(), w = read(), f = read();
            adde(u, v, w, f); adde(v, u, 0, -f);
        } EK();
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    EdmondsKarp::solution();
}
