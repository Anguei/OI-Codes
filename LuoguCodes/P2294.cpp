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
#define fn "1202"
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

const int N = 100 + 5;
int n, m, dis[N], cnt[N];
bool inq[N];
std::queue<int> q;
std::vector<Edge> g[N];

void clear() {
    memset(cnt, 0, sizeof cnt);
    memset(inq, false, sizeof inq); 
    while (!q.empty()) q.pop();
    rep(i, 0, N - 1) g[i].clear();
}

bool spfa(int s = 0) {
    memset(dis, 0xc0, sizeof dis); dis[s] = 0; q.push(s); inq[s] = true; cnt[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (const auto &e : g[u]) { int v = e.v, w = e.w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    inq[v] = true, q.push(v);
                    if (++cnt[v] >= n + 1) return true;
                }
            }
        }
    }
    return false;
}

void solution() {
    clear();
    n = read(), m = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        g[u - 1].push_back(Edge(v, w)); g[v].push_back(Edge(u - 1, -w));
    }
    rep(i, 0, n) g[n + 2].push_back(Edge(i, 0));
    puts(spfa(n + 2) ? "false" : "true");
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
    int T = read(); while (T--) solution();
}