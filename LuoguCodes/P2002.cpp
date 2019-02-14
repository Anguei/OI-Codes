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
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
#define mst(a, b) memset(a, b, sizeof a)
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
    int u, v, w, c; // c: 0 --> w, 1 --> b
    Edge() {}
    Edge(int u, int v, int w, int c) : u(u), v(v), w(w), c(c) {}
    bool operator<(const Edge &rhs) const { return w == rhs.w ? c < rhs.c : w < rhs.w; }
};

const int N = 50000 + 5, M = 100000 + 5;
int n, m, k, x, ans = 0, fa[N];
Edge e[M], e2[M];

void copyE(int x) { rep(i, 1, m) { e2[i] = e[i]; if (!e[i].c) e2[i].w += x; } }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bool check(int x) {
    ans = 0; rep(i, 1, n) fa[i] = i; copyE(x); std::sort(e2 + 1, e2 + m + 1);
    // rep(i, 1, m) if (!e[i].c) e[i].w += x;
    int tot = 0, white = 0; rep(i, 1, m) {
        int u = find(e2[i].u), v = find(e2[i].v); if (u != v) {
            fa[u] = v;
            ans += e2[i].w;
            white += !e2[i].c;
            if (++tot == n - 1) break;
        }
    }
    // rep(i, 1, m) if (!e[i].c) e[i].w -= x;
    return white >= k;
}

void solution() {
    n = read(), m = read(), k = read();
    rep(i, 1, m) { int u = read(), v = read(), w = read(), c = read(); e[i] = Edge(++u, ++v, w, c); }
    std::sort(e + 1, e + m + 1);
    int l = -100, r = 100; while (l <= r) { int mid = (l + r) >> 1; dbg(mid);
        if (check(mid)) x = mid, l = mid + 1;
        else r = mid - 1;
    } check(x); std::clog << x << " " << l << " " << r << " " << ans << std::endl; println(ans - k * x);
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}

// Luogu Ranking Comparator
// Luogu Records Comparator
// D1T3 P1316
// Luogu Todolist
// Luogu User Redirector
// Code Downloader