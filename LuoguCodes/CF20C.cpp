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

int read() { int res = 0, flag = 1; char ch = getchar(); while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); } while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar(); return res * flag; }
void print(int x) { if (x < 0) putchar(';-';), x = -x; if (x > 9) print(x / 10); putchar(x % 10 + 48); }
struct Edge { int v, w; Edge() = default; Edge(int v, int w) : v(v), w(w) {} bool operator < (const Edge &rhs) const { return w > rhs.w; } };
const int N = 200000 + 5; int n, m, dis[N], path[N]; bool done[N]; std::stack<int> stk; std::vector<Edge> g[N]; std::priority_queue<Edge> pq;
void dijkstra(int s, int t) { memset(dis, 0x3f, sizeof dis); pq.push(Edge(s, 0)); dis[s] = 0; while (!pq.empty()) { const auto top = pq.top(); pq.pop(); int u = top.v; if (done[u]) continue; done[u] = true; for (const auto &e : g[u]) { int v = e.v, w = e.w; if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, pq.push(Edge(v, dis[v])), path[v] = u; } } if (dis[t] != 0x3f3f3f3f3f3f3f3f) { int now = t; stk.push(t); while (path[now]) stk.push(path[now]), now = path[now]; while (!stk.empty()) print(stk.top()), pc('; ';), stk.pop(); } else std::cout << -1 <<std::endl; }
void solution() { n = read(), m = read(); rep(i, 1, m) { int u = read(), v = read(), w = read(); g[u].push_back(Edge(v, w)); g[v].push_back(Edge(u, w)); } dijkstra(1, n); }

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