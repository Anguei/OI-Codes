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
    int v, next;
    Edge() {}
    Edge(int v, int next) : v(v), next(next) {}
};

const int N = (1000 + 5) << 1;
int cnt, head[N], n, m, a[N], map[N][N], map2[N], vis[N], ans;
Edge e[N];

void dfs(int u) {
    if (vis[u]) return;
    rep(i, 1, map[u][0]) { if (!vis[map[u][i]]) dfs(map[u][i]); vis[u] = std::max(vis[u], vis[map[u][i]] + 1); }
    if (u > n) --vis[u]; ans = std::max(ans, vis[u]);
}

void solution() {
    n = read(), m = read(); rep(i, 1, m) {
        int tot = read(); dbg(tot); rep(j, 1, tot) dbg(j), a[j] = read(), map2[a[j]] = i, map[n + i][++map[n + i][0]] = a[j];
        rep(j, a[1] + 1, a[tot] - 1) if (map2[j] != i) map[j][++map[j][0]] = i + n;
    }
    logs("readed"); rep(i, 1, n) if (!vis[i]) dfs(i); println(ans + 1);
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