// luogu-judger-enable-o2
// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
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
    Edge() = default;
    Edge(int v, int w) : v(v), w(w) {}
};

struct Trie {
    int son[2];
    bool isEnd, haveSon;
};

const int N = 100000 + 5;
int n, tot = 0;
int dis[N];
std::vector<Edge> g[N];
Trie trie[N * 31];

void dfs(int u, int fa) {
    for (const auto &e : g[u]) {
        if (e.v != fa) {
            dis[e.v] = dis[u] ^ e.w;
            dfs(e.v, u);
        }
    }
}

void insert(int d) {
	int u = 0;
    for (int i = (1 << 30); i; i >>= 1) {
        bool id = i & d;
        if (!trie[u].son[id]) trie[u].son[id] = ++tot;
        u = trie[u].son[id];
    }
}

int find(int d) {
    int ans = 0, u = 0;
    for (int i = (1 << 30); i; i >>= 1) {
        bool id = i & d;
        if (trie[u].son[id ^ 1]) ans += i, u = trie[u].son[id ^ 1];
        else u = trie[u].son[id];
    }
    return ans;
}

void solution() {
    n = read();
    rep(i, 2, n) {
        int u = read(), v = read(), w = read();
        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
    }
    dfs(1, 1);
    rep(i, 1, n) insert(dis[i]);
    int ans = 0;
    rep(i, 1, n) ans = std::max(ans, find(dis[i]));
    print(ans), puts("");
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

