// luogu-judger-enable-o2
// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
#include <cmath>
#include <cctype>
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
//#define int long long
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
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

const int N = 4000 + 5;
int nameCnt = 0, sccCnt = 0, dfsClock = 0, n, m;
int low[N << 1], dfn[N << 1], color[N << 1], size[N << 1];
bool ins[N << 1];
std::vector<int> g[N << 1], dag[N << 1];
std::stack<int> stk;
std::map<std::string, int> cp;
std::string map[N << 1];

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

void solution() {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	n = read();
	rep(i, 1, n) {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		map[++nameCnt] = s1, cp[s1] = nameCnt;
		map[++nameCnt] = s2, cp[s2] = nameCnt;
		g[nameCnt - 1].push_back(nameCnt);
	}
	m = read();
	while (m--) {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		g[cp[s2]].push_back(cp[s1]);
	}
	rep(i, 1, nameCnt) if (!dfn[i]) tarjan(i);
	rep(i, 1, (n << 1)) std::cout << (size[color[cp[map[i++]]]] > 1 ? "Unsafe" : "Safe") << std::endl;
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
