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

const int N = 10000 + 5, M = 100000 + 5;
int n, m, s, t, ecnt = 1, head[N];

struct Edge {
    int v, w, next;
    Edge() = default;
    Edge(int v, int w, int next) : v(v), w(w), next(next) {}
} e[M << 1];

void add(int u, int v, int w) {
    e[++ecnt] = Edge(v, w, head[u]);
    head[u] = ecnt;
}

namespace EdmondsKarp {
    struct Pre {
        int v, e;
        Pre() = default;
        Pre(int v, int e) : v(v), e(e) {}
    } pre[N];
    bool inq[N]; 
    std::queue<int> q;
    bool bfs() {
        while (!q.empty()) q.pop();
        memset(inq, 0, sizeof inq); memset(pre, 0, sizeof pre);
        inq[s] = true; q.push(s); while (!q.empty()) {
            int u = q.front(); q.pop(); for (int i = head[u]; i; i = e[i].next) {
                int v = e[i].v; if (!inq[v] && e[i].w) {
                    pre[v] = Pre(u, i);
                    if (v == t) return true;
                    inq[v] = true; q.push(v);
                }
            }
        }
        return false;
    }

    int ekCnt = 0;
    int EK() {
        int ans = 0; while (bfs()) { dbg(++ekCnt); dbg(ans);
            int min = -1ull / 2;
            for (int i = t; i != s; i = pre[i].v) dbg(i), min = std::min(min, e[pre[i].e].w);
            for (int i = t; i != s; i = pre[i].v) e[pre[i].e].w -= min, e[pre[i].e ^ 1].w += min;
            ans += min;
        } return ans;
    }

    void solution() {
        n = read(), m = read(), s = read(), t = read();
        while (m--) {
            int u = read(), v = read(), w = read();
            add(u, v, w); add(v, u, 0);
        } println(EK());
    }
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
    EdmondsKarp::solution();
}

// Luogu Ranking Comparator
// Luogu Records Comparator
// D1T3 P1316
// 不要颓废
// 不 要 颓 废
// 不  要  颓  废
// 不   要   颓   废
// 不    要    颓    废
// 不     要     颓     废