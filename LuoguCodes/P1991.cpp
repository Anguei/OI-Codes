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

struct Pos {
    int x, y;
    Pos() = default;
    Pos(int x, int y) : x(x), y(y) {}
};

struct Edge {
    int u, v;
    double w;
    Edge() = default;
    Edge(int u, int v, double w) : u(u), v(v), w(w) {}
};

const int P = 500 + 5, S = 500 + 5;
int s, p, fa[P];
Pos pos[P];
std::vector<Edge> e;

int sqr(int x) {
    return x * x;
}

double dis(int a, int b) {
    return sqrt(sqr(pos[a].x - pos[b].x) + sqr(pos[a].y - pos[b].y));
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    fa[b] = a;
}

void solution() {
    s = read(), p = read();
    rep(i, 1, p) fa[i] = i;
    rep(i, 1, p) {
        int x = read(), y = read();
        pos[i] = Pos(x, y);
    }
    rep(i, 1, p) rep(j, i + 1, p) {
        e.push_back(Edge(i, j, dis(i, j)));
    }
    std::sort(e.begin(), e.end(), [](const Edge &e1, const Edge &e2) {
        return e1.w < e2.w;
    });
    int cnt = p - s; double ans = 0;
    for (auto it : e) {
        int u = it.u, v = it.v;
        if (find(u) != find(v)) {
            merge(u, v);
            ans = std::max(ans, it.w);
            if (--cnt <= 0) {
                std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
                return;
            }
        }
    }

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