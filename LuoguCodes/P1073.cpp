// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 测试面包插件，提交 P1073
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
#define sum(l, r) (s[r] - s[l - 1])
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

const int N = 100000;
int n, m, ans = -1ull / 2;
int price[N], min[N], dp[N];
std::vector<int> g[N];

void dfs(int u, int last, int now) {
    bool flag = false;
    now = std::min(now, price[u]);
    if (min[u] > now) min[u] = now, flag = true;
    // greedy
    if (dp[u] < std::max(dp[last], price[u] - now)) dp[u] = std::max(dp[last], price[u] - now), flag = true;
    if (flag) for (const auto &v : g[u]) dfs(v, u, now);
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
#endif
    dbg(ans);
    n = read(), m = read();
    rep(i, 1, n) price[i] = read();
    rep(i, 1, m) {
        int u = read(), v = read(), opt = read();
        g[u].push_back(v);
        if (opt == 2) g[v].push_back(v); // sillyBug: g[v].push_back(v);
    }
    memset(min, 0x3f, sizeof min);
    dfs(1, 0, ans);
    print(dp[n]), puts("");
}