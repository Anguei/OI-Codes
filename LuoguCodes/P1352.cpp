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

const int N = 10000 + 5;
std::vector<int> g[N];
int n, root, h[N], dp[2][N], ind[N];

void dfs(int u, int fa) {
    dp[0][u] = 0; dp[1][u] = h[u];
    for (const auto &v : g[u]) if (v != fa) {
        dfs(v, u);
        dp[0][u] += std::max(dp[0][v], dp[1][v]);
        dp[1][u] += dp[0][v];
    }
}

void solution() {
    n = read();
    rep(i, 1, n) h[i] = read();
    rep(i, 2, n) {
        int u = read(), v = read();
        g[u].push_back(v); g[v].push_back(u);
        ++ind[u]; ++ind[v];
    }
    rep(i, 1, n) if (ind[i] == 1) { root = i; break; }
    dfs(root, root);
    print(std::max(dp[0][root], dp[1][root])), puts("");
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