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
#pragma GCC optimize(3)
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

struct Time {
	int s, t, d;
	Time(int s, int t, int d) : s(s), t(t), d(d) {}
	Time() = default;
	bool operator < (const Time &rhs) const {
		return s + d < rhs.s + rhs.d;
	}
};

const int N = 100000 + 5;
int n, sccCnt, dfsClock;
int low[N << 1], dfn[N << 1], color[N << 1], size[N << 1];
bool ins[N << 1];
int s[N], t[N], d[N];
std::stack<int> stk;
std::vector<int> g[N << 1];
Time times[N];

namespace Tarjan
{
	void clear() {
		sccCnt = dfsClock = 0;
		rep(i, 0, N - 1) g[i].clear();
	}

	void input() {
		rep(i, 1, n) { 
			s[i] = read(), t[i] = read(); 
			d[i] = (t[i] - s[i] + 1) >> 1;
		}
	}

	void build() {
		rep(i, 1, n) rep(j, 1, i - 1) {
			if (std::min(s[i] + d[i], s[j] + d[j]) > std::max(s[i], s[j])) {
				g[i].push_back(n + j); g[j].push_back(n + i);
			}
			if (std::min(s[i] + d[i], t[j]) > std::max(s[i], t[j] - d[j])) {
				g[i].push_back(j); g[n + j].push_back(n + i);
			}
			if (std::min(t[i], s[j] + d[j]) > std::max(t[i] - d[i], s[j])) {
				g[n + i].push_back(n + j); g[j].push_back(i);
			}
			if (std::min(t[i], t[j]) > std::max(t[i] - d[i], t[j] - d[j])) {
				g[n + i].push_back(j); g[n + j].push_back(i);
			}
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
				color[sccCnt] = u;
				++size[sccCnt];
				u = stk.top(); stk.pop(); ins[u] = false;
			} while (low[u] != dfn[u]);
		}
	}

	void scc() {
		rep(i, 1, n) if (!dfn[i]) tarjan(i);
	}

	void output() {
		rep(i, 1, n) if (color[i] == color[i + n]) {
			puts("NO"); return;
		}
		puts("YES");
	}

	void solve() {
		clear();
		input();
		build();
		scc();
		output();
	}
}

namespace Greedy
{
	void init() {
		rep(i, 1, n) {
			int s = read(), t = read(); int d = ((t - s) >> 1) + 1;
			times[i] = Time(s, t, d);
		}
		std::sort(times + 1, times + n + 1);
	}

	void answer() {
		int max = 0;
		rep(i, 1, n) {
			max = std::max(max, times[i].s) + times[i].d;
			dbg(max), dbg(times[i].t);
			if (max > times[i].t) {
				puts("NO");
				return;
			}
		}
		puts("YES");
	}

	void solve() {
		init();
		answer();
	}
}

signed main() {
#ifdef yyfLocal
	fileIn;
#endif
	while (std::cin >> n && n) 
		Greedy::solve();
		//Tarjan::solve();
}