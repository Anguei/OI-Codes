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

const int N = 100 + 5;
int n, m;
int ind[N];
std::queue<int> q;
std::vector<int> ans, g[N];

void toposort() {
    rep(i, 1, n) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (const auto &v : g[u]) if (--ind[v] == 0) q.push(v);
    }
}

void solve() {
    for (int i = 0; i < N; ++i) g[i].clear();
    ans.clear();
    memset(ind, 0, sizeof ind);
    while (m--) {
        int u = read(), v = read();
        g[u].push_back(v); ++ind[v];
    }
    toposort();
    for (int i = 0; i < ans.size(); ++i) printf("%lld%c", ans[i], " \n"[i == n - 1]);
}

signed main() {
    while (std::cin >> n >> m && n + m) solve();
}