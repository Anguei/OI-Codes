// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 测试面包插件，提交 P1726
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
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
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

const int N = 5000 + 5;
int n, m, dfsClock = 0, sccCnt = 0;
int dfn[N], low[N], color[N], size[N];
bool ins[N];
std::stack<int> stk;
std::vector<int> g[N], dag[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u), ins[u] =  true;
    for (const auto &v : g[u]) {
        if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            ++size[sccCnt];
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

signed main() {
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read(), opt = read();
        g[u].push_back(v);
        if (opt == 2) g[v].push_back(u);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    rep(i, 1, n) for (const auto &j : g[i]) if (color[i] != color[j]) g[color[i]].push_back(color[j]);
    int max = 0, id = 0;
    rep(i, 1, sccCnt) if (size[i] > max) max = size[i], id = i;
    print(max), puts(""); rep(i, 1, n) if (color[i] == id) print(i), pc('; ';); puts("");
}