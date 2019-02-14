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
#define fn "testdata"
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

struct Edge {
    int v, w;
    Edge () {}
    Edge (int v, int w) : v(v), w(w) {}
};

const int N = 1000 + 5;
int n, m, a[N], times[N];
double dis[N];
bool inq[N];
std::vector<Edge> g[N];

std::queue<int> q;
bool check(double mid) {
    while (!q.empty()) q.pop(); std::fill(dis + 1, dis + n + 1, 1e10); memset(inq, false, sizeof inq); memset(times, 0, sizeof times); dis[1] = 0; inq[1] = times[1] = 1; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (const auto &e : g[u]) { int v = e.v; double w = static_cast<double>(e.w) * mid - static_cast<double>(a[u]);
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; times[v] = times[u] + 1;
                if (times[v] > n + 1) return true;
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
    return false;
}

void solution() {
    n = read(), m = read();
    rep(i, 1, n) a[i] = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        g[u].push_back(Edge(v, w));
    }
    double l = 0, r = 1e10; int eft = 100; while (eft--) {
        double mid = (l + r) / 2; dbg(mid); if (check(mid)) l = mid; else r = mid;
    }
    std::cout << std::fixed << std::setprecision(2) << l << std::endl;
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