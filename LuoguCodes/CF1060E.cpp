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

const int N = 200000 + 5;
int n, ans = 0, size[N], depth[N], cnt[N];
std::vector<int> g[N];

void dfs(int u, int fa) {
    ++cnt[depth[u]];
    size[u] = 1;
    for (const auto &v : g[u]) {
        if (v != fa) {
            depth[v] = depth[u] ^ 1;
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

void solution() {
    n = read();
    rep(i, 2, n) {
        int u = read(), v = read();
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1, 1);
    rep(i, 1, n) ans += size[i] * (n - size[i]);
    ans += cnt[0] * cnt[1];
    print(ans >> 1), puts("");
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
    solution();
}