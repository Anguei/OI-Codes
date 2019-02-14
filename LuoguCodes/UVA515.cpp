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
#define pc(x) std::cout.put(x)
#define endln std::cout.put(';\n';)
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
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

struct Edge {
    int v, w;
    Edge() = default;
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 100 + 5;
int n, m, dis[N], cnt[N];
bool inq[N];
std::vector<Edge> g[N];
#define add(u, v, w) g[(u)].push_back(Edge((v), (w)))

std::queue<Edge> q;
bool spfa(int s) {
    memset(cnt, 0, sizeof cnt); memset(inq, false, sizeof inq); memset(dis, 0x3f, sizeof dis); dis[s] = 0;
    q.push(Edge(s, 0)); inq[s] = true;
    while (!q.empty()) {
        const auto front = q.front(); q.pop(); int u = front.v; inq[u] = false;
        for (const auto &e : g[u]) { int v = e.v, w = e.w; 
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    if (++cnt[v] > n + 1) return true;
                    q.push(Edge(v, dis[v])), inq[v] = true;
                }
            }
        }
    }
    return false;
}

void solution() {
    rep(i, 0, N - 1) g[i].clear();
    m = read();
    while (m--) {
        int x = read(), y = read(); std::string s; std::cin >> s; int c = read();
        int u = x + y, v = x - 1;
        if (s == "gt") add(u, v, -1 - c); else if (s == "lt") add(v, u, c - 1);
    }
    rep(i, 0, n) add(n + 1, i, 0);
    puts(spfa(n + 1) ? "successful conspiracy" : "lamentable kingdom");
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
    while (std::cin >> n && n) solution();
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}