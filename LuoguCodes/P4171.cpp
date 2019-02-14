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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define dbg2(x, y) std::clog << #x " = " << (x) << " " #y " = " << (y) << std::endl
#else
#define dbg(x) x
#define dbg2(x, y) 42
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

const char *ans[] = {"BAD", "GOOD"};
const int N = 100 + 5;
int n, m, dfsClock, sccCnt, low[N << 2], dfn[N << 2], color[N << 2];//, size[N << 1];
bool ins[N << 2];
std::vector<int> g[N << 2]; // A, B;
std::stack<int> stk;
// std::set<std::string> menu;
// std::map<std::string, int> map;

void clear() {
	dfsClock = sccCnt = 0;
    // menu.clear(); map.clear();
	// A.clear(); B.clear();
    // for (int i = 0; i < (N << 2); ++i) g[i].clear();
	for (int i = 0; i < (N << 1); ++i) g[i].clear();
	memset(dfn, 0, sizeof dfn); memset(low, 0, sizeof low); memset(color, 0, sizeof color);
	memset(ins, false, sizeof ins); while (!stk.empty()) stk.pop(); 
}

void input() {
    n = read(), m = read();
    rep(i, 1, m) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
		char c1 = s1[0], c2 = s2[0];
		int a = std::stoi(s1.substr(1)), b = std::stoi(s2.substr(1));
		if (c1 == ';m';) {
			if (c2 == ';m';) g[a + n].push_back(b), g[b + n].push_back(a);
			else if (c2 == ';h';) g[a + n].push_back(b + n), g[b].push_back(a);
		} else if (c1 == ';h';) {
			if (c2 == ';m';) g[a].push_back(b), g[b + n].push_back(a + n);
			else if (c2 == ';h';) g[a].push_back(b + n), g[b].push_back(a + n);
		}
        // if (!menu.count(s1)) {
            // menu.insert(s1);
            // map[s1] = menu.size();
        // }
        // if (!menu.count(s2)) {
            // menu.insert(s2);
            // map[s2] = menu.size();
        // }
        // int a = map[s1], b = map[s2];
		// A.push_back(map[s1]), B.push_back(map[s2]);
    }
}

// void build() {
	// for (int i = 0; i < m; ++i) {
		// g[A[i] + menu.size()].push_back(B[i]);
		// g[B[i] + menu.size()].push_back(A[i]);
	// }
// }

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const int &v : g[u]) {
        if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

void scc() {
    // for (const auto &i : map) if (!dfn[i.second]) tarjan(i.second);
	rep(i, 1, (n << 1)) if (!dfn[i]) tarjan(i);
}

void output() {
    bool flag = true;
    // for (const auto &i : map) if (color[i.second] == color[i.second + menu.size()]) puts(ans[flag = false]);
    // for (const auto &i : map) dbg2(color[i.second], color[i.second + menu.size()]);
	for (int i = 1; i <= n && flag; ++i) if (color[i] == color[i + n]) puts(ans[flag = false]);
    if (flag) puts(ans[true]);
}

void solve() {
    clear();
    input();
	//build();
    scc();
    output();
}

signed main() {
#ifdef yyfLocal
    fileIn;
#else
    #ifdef yyfLemon
        freopen("1823.in", "r", stdin);
        freopen("1823.out", "w", stdout);
    #endif
#endif
    int T = read(); while (T--) solve();
}