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
#define pc(x) std::cout.put(x)
#define endln std::cout.put(';\n';)
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
    int v, w, next;
    Edge() = default;
    Edge(int v, int w, int next) : v(v), w(w), next(next) {}
};

struct Pre {
    int v, e;
    Pre() = default;
    Pre(int v, int e) : v(v), e(e) {}
};

const int N = 100 * 2 + 5, M = 100 * 100 + 5;
int m, n, ecnt = 1, head[N], s = 203, t = 204, ans[N];
bool vis[N];
Edge e[M << 1];
Pre pre[M << 1];
std::queue<int> q;

inline void adde(int u, int v, int w) {
    e[++ecnt] = Edge(v, w, head[u]);
    head[u] = ecnt;
}

bool bfs() {
    memset(pre, 0, sizeof pre); memset(vis, 0, sizeof vis);
    while (!q.empty()) q.pop(); q.push(s); vis[s] = true; while (!q.empty()) {
        int u = q.front(); q.pop(); for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v, w = e[i].w; if (!vis[v] && w) {
                pre[v] = Pre(u, i);
                if (v == t) return true;
                q.push(v); vis[v] = true;
            }
        }
    } return false;
}

int EK() {
    int max = 0; while (bfs()) {
        int min = -1ull / 2;
        for (int i = t; i != s; i = pre[i].v) min = std::min(min, e[pre[i].e].w); max += min;
        for (int i = t; i != s; i = pre[i].v) e[pre[i].e].w -= min, e[pre[i].e ^ 1].w += min, ans[pre[i].v] = i;
    } return max;
}

void solution() {
    // 外籍编号 1 ~ m，英国编号 m + 1 ~ n
    m = read(), n = read();
    rep(i, 1, n) adde(i + n, t, 1), adde(t, i + n, 0); // 连接英国和汇点
    rep(i, 1, m) adde(s, i, 1), adde(i, s, 0); // 连接外籍和源点
    int a, b; while (std::cin >> a >> b && a != -1) adde(a, b + n, 1), adde(b + n, a, 0);
    println(EK()); rep(i, 1, n) if (ans[i]) print(i), pc('; ';), println(ans[i] - n);
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
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}

// Luogu Ranking Comparator
// Luogu Records Comparator
// D1T3 P1316
// 不要颓废
// 不 要 颓 废
// 不  要  颓  废
// 不   要   颓   废
// 不    要    颓    废
// 不     要     颓     废