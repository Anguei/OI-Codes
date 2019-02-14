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

const int N = 3000000 + 5;
int n, k, s = 1, ans = 1, ind[N], dis[N];
std::vector<int> g[N];

void topo() {
    rep(i, 1, n) if (ind[i] == 2) {
        s = i; return;
    }
}

void dfs(int u, int fa) {
    dbg(u);
    if (ind[u] == 1) { dis[u] = 0; return; }
    std::vector<int> vec;
    for (const auto &v : g[u]) {
        if (v != fa) {
            dfs(v, u);
            vec.push_back(dis[v] + 1);
        }
    }
    std::sort(vec.begin(), vec.end());
    dis[u] = vec.back();
    for (int i = vec.size() - 1; i >= 1; --i) {
        if (vec[i - 1] + vec[i] > k) { 
            ++ans;
            dis[u] = vec[i - 1];
        } else {
            break;
        }
    }
}

void solution() {
    n = read(), k = read();
    rep(i, 2, n) {
        int u = read(), v = read();
        g[u].push_back(v); g[v].push_back(u);
        ++ind[u], ++ind[v];
        if (ind[u] == 2) s = u;
        else if (ind[v] == 2) s = v;
    }
    dfs(s, 0);
    print(ans), puts("");
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