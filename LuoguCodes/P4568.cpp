// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <limits>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "2763"
#define ll long long
// #define int long long
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

#define JLOI 1
#define add(u, v, w) (g[(u)].push_back(Edge((v), (w))))

struct Edge { int v, w; Edge () {} Edge (int v, int w) : v(v), w(w) {} };
struct State { int v, w, cnt; State() {} State(int v, int w, int cnt) : v(v), w(w), cnt(cnt) {} bool operator < (const State &rhs) const { return w > rhs.w; } };

const int N = 10000 + 5, K = 20 + 5;
int n, m, k, s, t, dis[N][K];
bool done[N][K];
std::vector<Edge> g[N];
std::priority_queue<State> pq;

void dijkstra() {
	memset(dis, 0x3f, sizeof dis); dis[s][0] = 0; pq.push(State(s, 0, 0));
	while (!pq.empty()) { const State top = pq.top(); pq.pop(); int u = top.v, nowCnt = top.cnt; if (done[u][nowCnt]) continue; done[u][nowCnt] = true;
		for (const auto &e : g[u]) { int v = e.v, w = e.w;
			if (nowCnt < k && dis[v][nowCnt + 1] > dis[u][nowCnt]) { dis[v][nowCnt + 1] = dis[u][nowCnt]; pq.push(State(v, dis[v][nowCnt + 1], nowCnt + 1)); dbg(dis[v][nowCnt + 1]); }
			if (dis[v][nowCnt] > dis[u][nowCnt] + w) { dis[v][nowCnt] = dis[u][nowCnt] + w; pq.push(State(v, dis[v][nowCnt], nowCnt)); dbg(dis[v][nowCnt]); }
		}
	}
}

void solution() {
	n = read(), m = read(), k = read(); s = read() + JLOI, t = read() + JLOI;
	while (m--) { int u = read() + JLOI, v = read() + JLOI, w = read(); add(u, v, w), add(v, u, w);  }
	dijkstra(); int ans = std::numeric_limits<int>::max(); rep(i, 0, k) ans = std::min(ans, dis[t][i]); println(ans);
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

// 记得更改 JLOI 的取值了吗？ 
