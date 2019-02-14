// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 用老婆的插件提交 P2194
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
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define mod 1000000007
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

const int N = 100000 + 5;
int n, m, dfsClock = 0, sccCnt = 0, ans1 = 0, ans2 = 1;
int low[N], dfn[N], color[N], p[N], min[N], solutions[N];
bool ins[N];
std::stack<int> stk;
std::vector<int> g[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock; stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) { if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); else if (ins[v]) low[u] = std::min(low[u], dfn[v]); }
    if (low[u] == dfn[u]) { ++sccCnt; do { color[u] = sccCnt; min[sccCnt] = std::min(min[sccCnt], p[u]); u = stk.top(); stk.pop(); ins[u] = false; } while (low[u] != dfn[u]); }
}

signed main() {
    int n = read(); rep(i, 1, n) p[i] = read(), min[i] = -1ull / 2; int m = read(); rep(i, 1, m) { int u = read(), v = read(); g[u].push_back(v); }
    rep(i, 1, n) if (!dfn[i]) tarjan(i); rep(i, 1, sccCnt) ans1 += min[i]; print(ans1), pc('; ';);
    rep(i, 1, n) if (p[i] == min[color[i]]) ++solutions[color[i]]; rep(i, 1, sccCnt) ans2 = ans2 * solutions[i] % mod; print(ans2), puts("");
}