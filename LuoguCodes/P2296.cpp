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

const int N = 10000 + 5;
int n, m, start, end;
int dis[N], ind[N], outd[N];
bool inq[N];
std::queue<int> q;
std::vector<int> g1[N], g2[N];

void bfs1(int s) {
    q.push(s); inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); dbg(u);
        for (auto &v : g2[u]) {
            ++ind[v];
            if (!inq[v]) q.push(v), inq[v] = true;
        }
    }
}

void spfa(int s) {
    memset(dis, 0x3f, sizeof dis);
    memset(inq, false, sizeof inq);
    q.push(s); dis[s] = 0; inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        dbg(u);
        for (auto &v : g1[u]) {
            if (ind[v] == outd[v] && dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1; 
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
    if (dis[end] == 0x3f3f3f3f3f3f3f3f) puts("-1");
    else print(dis[end]), puts("");
}

signed main() {
    n = read(), m = read();
    rep(i, 1, m)  {
        int u = read(), v = read();
        g1[u].push_back(v); g2[v].push_back(u); ++outd[u];
    }
    start = read(), end = read();
    bfs1(end);
    spfa(start);
}