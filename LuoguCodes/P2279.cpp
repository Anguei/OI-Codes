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
#define fn "1217"
#define ll long long
#define int long long
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

const int N = 1000 + 5;
int n, a[N], fa[N], b[N], dis[N], o[N], ans = 0;
std::vector<int> g[N];

void solution() {
    n = read();
    b[1] = 1, o[1] = o[0] = N;
    rep(i, 2, n) fa[i] = read(), dis[i] = dis[fa[i]] + 1, b[i] = i, o[i] = N;
    std::sort(b + 1, b + n + 1, [](int a, int b) { return dis[a] > dis[b]; });
    rep(i, 1, n) { int v = b[i], w = fa[v], u = fa[fa[v]];
        o[v] = std::min(o[v], std::min(o[w] + 1, o[u] + 2));
        if (o[v] > 2) {
            o[u] = 0, ++ans;
            o[fa[u]] = std::min(o[fa[u]], 1ll), o[fa[fa[u]]] = std::min(o[fa[fa[u]]], 2ll);
        }
    }
    println(ans);
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
    solution();
}