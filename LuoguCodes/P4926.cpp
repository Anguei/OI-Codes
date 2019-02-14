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
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
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

struct Flag {
    int o, a, b, k;
    Flag() = default;
    Flag(int o, int a, int b, int k) : o(o), a(a), b(b), k(k) {}
};

struct Edge {
    int next, v; double w;
    Edge() = default;
    Edge(int next, int v, double w) : next(next), v(v), w(w) {}
};

const int N = 1000 + 5;
int n, s, t, cnt = 0, c[N], fr[N], head[N];
bool ok = false, inq[N];
double l = 0, r = 1e18, dis[N];
Flag fl[N];
Edge e[N << 1];
std::queue<int> q;

void add(int u, int v, double w) { e[++cnt] = Edge(head[u], v, w); head[u] = cnt; }

bool check(double T) {
    cnt = 0; memset(head, 0, sizeof head); memset(fr, 0, sizeof fr); while (!q.empty()) q.pop();
    rep(i, 0, n) dis[i] = 1, fr[i] = 0, inq[i] = true, q.push(i);
    rep(i, 1, n) if (c[i]) add(i, 0, 1.0 / c[i]), add(0, i, c[i]);
    rep(i, 1, s) {
        int A = fl[i].a, B = fl[i].b, k = fl[i].k, o = fl[i].o;
        if(o == 1) add(B, A, k - T); else add(B, A, 1.0 / (k + T));
    }
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] < dis[u] * e[i].w) {
                dis[v] = dis[u] * e[i].w;
                fr[v] = fr[u] + 1;
                if (fr[v] == n + 2) return true;
                else if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
    return false;
}

void solution() {
    n = read(), s = read(), t = read();
    rep(i, 1, s) {
        int o = read(), a = read(), b = read(), k = read(); fl[i] = Flag(o, a, b, k);
        if (o == 1) r = std::min(r, static_cast<double>(k));
    }
    rep(i, 1, t) { int C = read(), x = read(); c[C] = x; }
    dbg(r);
    rep(kase, 0, 99) { double mid = (l + r) / 2; if (check(mid)) ok = l = mid; else r = mid; }
    if (l != 0) std::cout << std::fixed << std::setprecision(10) << l << std::endl; else puts("-1");
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
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}