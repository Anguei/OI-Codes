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
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
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
int n, m, dfsClock = 0, cutCnt = 0;
int low[N], dfn[N], size[N], ans[N];
bool isCut[N];
std::vector<int> g[N];

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++dfsClock;
    size[u] = 1;
    int child = 0, k = 0;
    for (const auto &v : g[u]) {
        if (!dfn[v]) {
            tarjan(v, fa);
            size[u] += size[v];
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u]) 
            {
                if (u != fa) isCut[u] = true;
                ans[u] += (n - size[v]) * size[v];
                k += size[v];
                if (u == fa) ++child;
            }
        } 
        else low[u] = std::min(low[u], dfn[v]);
    }
    if (child >= 2 && u == fa) isCut[u] = true;
    if (!isCut[u]) ans[u] = (n - 1) << 1;
    else ans[u] += (k + 1) * (n - k - 1) + n - 1;
}

signed main() {
#ifdef yyfLemon
    freopen("1123.in", "r", stdin);
    freopen("1123.out", "w", stdout);
#endif
#ifdef yyfLocal
    fileIn;
    fileOut;
#endif
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        g[u].push_back(v), g[v].push_back(u);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i, i);
    rep(i, 1, n) print(ans[i]), puts("");
}