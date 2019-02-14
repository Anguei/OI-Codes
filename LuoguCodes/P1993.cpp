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
    Edge() = default;
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 10000 + 5;
int n, m, dis[N];
bool vis[N];
std::vector<Edge> g[N];

void spfa(int u) {
    vis[u] = true;
    for (const auto &e : g[u]) { int v = e.v, w = e.w; if (dis[v] > dis[u] + w)
        if (vis[v]) puts("No"), exit(0);
        else dis[v] = dis[u] + w, spfa(v);
    }
    vis[u] = false;
}

void solution() {
    memset(dis, 0x3f, sizeof dis);
    n = read(), m = read();
    while (m--) {
        // 对于每个 x_i - x_j <= c_k 的条件
        // 可以看作三角不等式当中的 x_i <= x_j + c_k
        // 所以可以把 x_j 当作起点，x_i 当作终点
        // 即从 x_j 连一条到 x_i 的长度为 c_k 的边
        int opt = read();                               //      题意                         转化结果
        if (opt == 1) {                                 // x_a - x_b >= c     -->     x_b - x_a <= -c
            int a = read(), b = read(), c = read();
            g[a].push_back(Edge(b, -c));
        } else if (opt == 2) {                          // x_a - x_b <= c     -->     x_a - x_b <= c
            int a = read(), b = read(), c = read();
            g[b].push_back(Edge(a, c));
        } else if (opt == 3) {                          // x_a = x_b          -->     x_a - x_b <= 0, x_b - x_a <= 0
            int a = read(), b = read();
            g[b].push_back(Edge(a, 0)); g[a].push_back(Edge(b, 0));
        }
    }
    rep(i, 1, n) g[0].push_back(Edge(i, 0)); // 相当于新建了 n 个 x_i - x_0 <= 0 的约束条件（x_0 = 0)，用于求出一组负数解
    rep(i, 1, n) spfa(i);
    puts("Yes");
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
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}