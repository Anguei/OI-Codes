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
// #define int long long
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

const int N = 1500 + 5;
int n, root, ind[N], dp[2][N];
std::vector<int> g[N];

void clear() {
    for (int i = 0; i < N; ++i) g[i].clear();
    memset(ind, 0, sizeof ind);
    memset(dp, 0, sizeof dp);
}

void input() {
    rep(i, 1, n) {
        int u, num; scanf("%d:(%d)", &u, &num); ++u;
        while (num--) {
            int son = read() + 1;
            ++ind[son]; g[u].push_back(son);
        }
    }
    rep(i, 1, n) if (!ind[i]) { root = i; break; }
    // rep(i, 1, n) std::clog << ind[i] << " "; std::clog << std::endl;
    dbg(root);
}

void solve(int u, int fa) {
    dp[1][u] = 1;
    for (const auto &v : g[u]) if (v != fa) {
        solve(v, u);
        dp[0][u] += dp[1][v]; 
        dp[1][u] += std::min(dp[1][v], dp[0][v]);
    }
}

void output() {
    print(std::min(dp[0][root], dp[1][root])), puts("");
}

void solution() {
    clear();
    input();
    solve(root, root);
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
    while (std::cin >> n) solution();
}