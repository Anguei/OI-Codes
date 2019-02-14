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
#define fn "2438"
#define ll long long
// #define int long long
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

const int N = 1000000 + 5;
int n, m, dfsClock = 0, sccCnt = 0, ans = 0, dfn[N], low[N], color[N], ind[N], size[N];
bool flag = false, ins[N];
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock; stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    if (low[u] == dfn[u]) { ++sccCnt; do { color[u] = sccCnt; ++size[sccCnt]; u = stk.top(); stk.pop(); ins[u] = false; } while (low[u] != dfn[u]); }
}

void solution() {
    n = read(), m = read();
    while (m--) { int u = read(), v = read(); g[u].push_back(v); }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(u, 1, n) for (const auto &v : g[u]) if (color[u] != color[v]) dag[color[u]].push_back(color[v]), ++ind[color[v]];
    rep(i, 1, sccCnt) { if (!flag && !ind[i] && size[i] == 1) { int pd = 0; for (const auto &j : dag[i]) if (ind[j] == 1) pd = 1; if (!pd) flag = 1; } if (!ind[i]) ++ans; }
    ans -= flag; std::cout << std::fixed << std::setprecision(6) << 1.0 - static_cast<double>(ans) / static_cast<double>(n) << std::endl;
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