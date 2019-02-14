// luogu-judger-enable-o2
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
#define fn "travel"
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

struct Edge {
	int u, v, next;
	Edge() = default;
	Edge(int u, int v, int next) : u(u), v(v), next(next) {}
};

const int N = 5000 + 5;
int n, m, depth, cnt, x, y, ans[N], bns[N], head[N];
bool vis[N];
std::vector<int> g[N];
Edge e[N << 1];

namespace Tree {
	void dfs(int u, int fa) {
	    if (!vis[u]) print(u), pc('; ';); vis[u] = true;
	    for (const auto &v : g[u]) {
	        if (v != fa)
	            dfs(v, u);
	    }
	}
}
void tree_solution() {
    Tree::dfs(1, -1); endln;
}

void add(int u, int v) {
	e[++cnt] = Edge(u, v, head[u]); head[u] = cnt;
}

void dfs(int u, int fa) {
	if (vis[u]) return; vis[u] = true;
	bns[++depth] = u;
	for (const auto &v : g[u]) if (v != fa) if ((v == y && u == x) || (v == x && u == y)) continue; else dfs(v, u);
}

bool check() { rep(i, 1, n) if (ans[i] ^ bns[i]) return ans[i] >= bns[i]; }
void update() { rep(i, 1, n) ans[i] = bns[i]; }

void solution() {
    n = read(), m = read(); // memset(head, -1, sizeof head);
	rep(i, 1, m) { int u = read(), v = read(); g[u].push_back(v); g[v].push_back(u); add(u, v); add(v, u); };
    rep(i, 1, n) std::sort(g[i].begin(), g[i].end());
    if (m == n - 1) { tree_solution(); return; }
	for (int i = 1; i <= cnt; i += 2) { // 遍历每条边 
		depth = 0, x = e[i].u, y = e[i].v; memset(vis, false, sizeof vis);
		dfs(1, -1);
		if (depth < n) continue; if (!ans[1] || check()) update();
	}
	rep(i, 1, n) print(ans[i]), pc('; ';); endln;
}


signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else
    // freopen(fn".in", "r", stdin);
    // freopen(fn".out", "w", stdout);
#endif
    logs("main.exe");
    solution();
}
