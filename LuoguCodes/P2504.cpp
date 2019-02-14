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
#define fn "2429"
#define ll long long
//#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
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

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct Pos {
    int x, y;
    Pos() = default;
    Pos(int x, int y) : x(x), y(y) {}
};

const int N = 5000000 + 5;
int n, m, cnt, dis[N], fa[N];
Pos pos[N];
Edge e[N];

int sqr(int x) {
    return x * x;
}

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    //a = find(a), b = find(b);
    fa[b] = a;
}

void solution() {
    m = read();
    rep(i, 1, m) dis[i] = read();
    n = read();
    rep(i, 1, n) {
        int x = read(), y = read();
        pos[i] = Pos(x, y);
    }
    rep(i, 1, n) fa[i] = i;
    rep(i, 1 ,n) rep(j, i + 1, n) {
        int x = sqr(pos[i].x - pos[j].x), y = sqr(pos[i].y - pos[j].y);
        int d = sqrt(x + y);
        if (d * d < x + y) d += 1;
        e[++cnt] = Edge(i, j, d);
    }
    std::sort(e + 1, e + cnt + 1, [](const Edge &e1, const Edge &e2) { return e1.w < e2.w; });
    int max = 0, ans = 0;
    rep(i, 1, cnt) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x != y) {
            merge(x, y);
            max = std::max(max, e[i].w);
        }
    }
    rep(i, 1, m) ans += (dis[i] >= max);
    print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}