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
//#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, b, a) for (register int i = (b); i >= (a); --i)
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

const int N = 2000000 + 5;
int n, m, sccCnt, dfsClock;
int dfn[N], low[N], color[N], size[N], ind[N];
bool ins[N], inq[N];
std::stack<int> stk;
std::vector<int> g[N];

void input();
void scc();
void tarjan(int);
void output();

signed main() {
#ifdef yyfLocal
	fileIn;
#endif
	input();
	scc();
	output();
}

void input() {
	n = read(), m = read();
	rep(i, 1, m) {
		int a = read(), va = read(), b = read(), vb = read();
		// 位运算该怎么写啊！
		//g[a + n * (va ^ 1)].push_back(b);
		//g[b + n * (vb ^ 1)].push_back(a);
		if (va && vb) { // a, b 都真，-a -> b, -b -> a
			g[a + n].push_back(b);
			g[b + n].push_back(a);
		} else if (!va && vb) { // a 假 b 真，a -> b, -b -> -a
			g[a].push_back(b);
			g[b + n].push_back(a + n);
		} else if (va && !vb) { // a 真 b 假，-a -> -b, b -> a
			g[a + n].push_back(b + n);
			g[b].push_back(a);
		} else if (!va && !vb) { // a, b 都假，a -> -b, b -> -a
			g[a].push_back(b + n);
			g[b].push_back(a + n);
		}
		// 题解写法
		//g[a + n * (va ^ 1)].push_back(b + vb * n);
		//g[b + n * (vb ^ 1)].push_back(a + va * n);
		// 自己的写法
		//g[a + n * (va ^ 1)].push_back(b + (vb ^ 1) * n);
		//g[b + n * (vb ^ 1)].push_back(a + (va ^ 1) * n);
	}
}

void scc() {
	rep(i, 1, (n << 1)) if (!dfn[i]) tarjan(i);
	rep(i, 1, n) if (color[i] == color[i + n]) {
		puts("IMPOSSIBLE");
		exit(0);
	}
}

void tarjan(int u) {
	low[u] = dfn[u] = ++dfsClock;
	stk.push(u); ins[u] = true;
	for (const auto &v : g[u]) {
		if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++sccCnt;
		do {
			color[u] = sccCnt;
			++size[sccCnt];
			u = stk.top(); stk.pop(); ins[u] = false;
		} while (low[u] != dfn[u]);
	}
}

void output() {
	puts("POSSIBLE");
	rep(i, 1, n) print((color[i] < color[i + n])), pc('; ';);
	puts("");
}