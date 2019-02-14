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
#define fn "4720"
#define ll long long
#define int long long
#define pc(x) std::cout.put(x)
#define endln std::cout.put(';\n';)
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

const int N = 2000 + 5, V = 300 + 5;
int n, m, v, e, c[N], d[N], map[V][V];
double k[N], dp[N][N][2], ans = 1e18;

void solution() {
    n = read(), m = read(), v = read(), e = read(); memset(map, 0x3f, sizeof map);
    rep(i, 1, n) c[i] = read(); rep(i, 1, n) d[i] = read();
    rep(i, 1, n) std::cin >> k[i];
    rep(i, 1, e) { int u = read(), v = read(), w = read(); map[u][v] = map[v][u] = std::min(map[v][u], w); }
    rep(k, 1, v) rep(i, 1, v) rep(j, 1, v) map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
    rep(i, 1, v) map[i][i] = map[i][0] = map[0][i] = 0;
    rep(i, 0, n) rep(j, 0, m) dp[i][j][1] = dp[i][j][0] = 1e18; dp[1][0][0] = dp[1][1][1] = 0;
    rep(i, 2, n) {
        dp[i][0][0] = dp[i - 1][0][0] + map[c[i - 1]][c[i]];
        rep(j, 1, std::min(i, m)) {
            int c1 = c[i - 1], c2 = d[i - 1], c3 = c[i], c4 = d[i];
            // std::clog << c1 << " " << c2 << " " << c3 << " " << c4 << std::endl;
            dp[i][j][0] = std::min(dp[i][j][0], std::min(dp[i - 1][j][0] + map[c1][c3], dp[i - 1][j][1] + map[c1][c3] * (1 - k[i - 1]) + map[c2][c3] * k[i - 1]));
            dp[i][j][1] = std::min(dp[i][j][1], std::min(dp[i - 1][j - 1][0] + map[c1][c3] * (1 - k[i]) + map[c1][c4] * k[i], dp[i - 1][j - 1][1] + map[c2][c4] * k[i] * k[i - 1] + map[c2][c3] * k[i - 1] * (1 - k[i]) + map[c1][c4] * (1 - k[i - 1]) * k[i] + map[c1][c3] * (1 - k[i - 1]) * (1 - k[i])));
        }
    }
    rep(i, 0, m) ans = std::min(ans, std::min(dp[n][i][0], dp[n][i][1])); std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
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
    std::ios::sync_with_stdio(false);
    solution();
}