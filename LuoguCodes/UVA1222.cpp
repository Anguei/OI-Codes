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
#include <sstream>
#include <iostream>
#include <algorithm>
#define fn "task"
#define ll long long
// #define int long long
#define pc(x) std::cout.put(x)
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
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

struct Edge {
    int v, w;
    Edge() = default;
    Edge(int v, int w) : v(v), w(w) {}
};

const int N = 200 + 5;
int n, m, tot, dp[N][N], son[N], w[N];
bool ok[N];
std::vector<Edge> g[N];
std::map<std::string, int> map;
std::string line;

void clear() {
    std::stringstream ss; ss << line;
    ss >> n >> m; // dbg(n), dbg(m); ss.clear();
    tot = 0;
    map.clear();
    rep(i, 0, N - 1) g[i].clear();
    memset(dp, 0x3f, sizeof dp);
    memset(w, 0, sizeof w); w[0] = 0x3f3f3f3f;
    memset(ok, false, sizeof ok);
    rep(i, 1, n) son[i] = 1;
}

void input() {
    rep(i, 1, n) {
        std::string s; int t;
        std::cin >> s >> t;
        if (!map.count(s)) map[s] = ++tot;
        int u = map[s]; w[u] = t;
        while (std::cin.get() != ';\n';) {
            std::cin >> s;
            if (!map.count(s)) map[s] = ++tot;
            int v = map[s]; ++son[u]; ok[v] = true;
            g[u].push_back(Edge(v, w[u]));
        }
    }
    rep(i, 1, n) if (!ok[i]) ++son[0], g[0].push_back(Edge(i, w[0]));
}

void solve(int u, int fa) {
    dp[u][0] = 0;
    son[u] = 1;
    for (const auto &e : g[u]) if (e.v != fa) {
        const int &v = e.v;
        solve(v, u);
        son[u] += son[v];
        per(j, m, 0) rep(k, 0, j) dp[u][j] = std::min(dp[u][j], dp[u][j - k] + dp[v][k]);
    }
    rep(i, 1, son[u]) dp[u][i] = std::min(dp[u][i], w[u]);
}

void output() {
    print(dp[0][m]), pc(';\n';);
}

void solution() {
    clear();
    input();
    solve(0, -1);
    output();
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
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    while (std::getline(std::cin, line) && line[0] != ';#';) solution();
}