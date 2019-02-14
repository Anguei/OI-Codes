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
#define int long long
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
    Edge() = default;
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 50000 + 5;
int n, max, /*min, */dis[N];
bool inq[N];
std::vector<Edge> g[N];
std::queue<int> q;

void clear() {
    n = max = 0; ;// min = -1ull / 2;
    for (int i = 0; i < N; ++i) g[i].clear();
}

void spfa(int s) {
    memset(dis, 0xcf, sizeof dis);
    memset(inq, 0, sizeof inq);

    q.push(s); dis[s] = 0; inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (const auto &e : g[u]) {
            int v = e.v, w = e.w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) q.push(v);//, inq[v] = true;
            }
        }
    }
}

void solution() {
    clear();
    n = read();
    rep(i, 1, n) {
        int a = read(), b = read(), c = read();
        g[a].push_back(Edge(b + 1, c));
        max = std::max(max, b + 1); // min = std::min(min, a);
    }
    rep(i, 1, max) g[i - 1].push_back(Edge(i, 0)), g[i].push_back(Edge(i - 1, -1));
    spfa(0);
    print(dis[max]), puts("");
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
    int T = read(); while (T--) { solution(); if (T) puts(""); }
}