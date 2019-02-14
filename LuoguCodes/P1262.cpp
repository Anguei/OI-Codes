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

const int N = 3000 + 5;
int n, p, r, ans = 0, sccCnt = 0, dfsClock = 0, money[N], low[N], dfn[N], color[N], w[N], ind[N];
bool ins[N];
std::vector<int> g[N], dag[N];
std::stack<int> stk;

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock; stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    if (low[u] == dfn[u]) { ++sccCnt; do { color[u] = sccCnt; w[sccCnt] = std::min(w[sccCnt], money[u]); u = stk.top(); stk.pop(); ins[u] = false; } while (low[u] != dfn[u]); }
}

void solution() {
    memset(money, 0x3f, sizeof money); 
    memset(w, 0x3f, sizeof w);
    n = read(), p = read(); rep(i, 1, p) { int u = read(), cost = read(); money[u] = cost; }
    r = read(); rep(i, 1, r) { int a = read(), b = read(); g[a].push_back(b); }
    rep(i, 1, n) if (!dfn[i] && money[i] <= 20000) tarjan(i);
    rep(i, 1, n) if (!dfn[i]) { printf("NO\n%lld\n", i); return; }
    rep(u, 1, n) for (const auto &v : g[u]) if (color[u] != color[v]) dag[color[u]].push_back(color[v]), ++ind[color[v]];
    printf("YES\n"); rep(i, 1, sccCnt) if (!ind[i]) ans += w[i]; print(ans), endln;
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