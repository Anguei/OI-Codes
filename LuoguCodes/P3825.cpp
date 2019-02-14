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
#define fn "task"
#define ll long long
// #define int long long
#define pc(x) std::cout.put(x)
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

int read() { int res = 0, flag = 1; char ch = std::cin.get(); while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); } while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get(); return res * flag; }
char get() { char res; std::cin >> res; return res; }
void print(int x) { if (x < 0) std::cout.put(';-';), x = -x; if (x > 9) print(x / 10); std::cout.put(x % 10 + 48); }

const int N = (50000 << 1) + 5;
int n, d, m, dfsClock, sccCnt, isx[N], var1[N << 1], val1[N << 1], var2[N << 1], val2[N << 1], chosen[N], color[N], dfn[N], low[N];
bool flag = false, ins[N];
std::string s;
std::vector<int> g[N];
std::stack<int> stk;

int transform(int a, int b) { if (s[a] == ';a';) return b == ';B'; ? a : a + n; if (s[a] == ';b'; || s[a] == ';c';) return b == ';A'; ? a : a + n; return b == ';C'; ? a + n : a; }
int convert(int x) { return x > n ? x - n : x + n; }
void add_edge(int u, int v) { g[u].push_back(v); }

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsClock; stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]); else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    if (low[u] == dfn[u]) { ++sccCnt; do { color[u] = sccCnt; u = stk.top(); stk.pop(); ins[u] = false; } while (low[u] != dfn[u]); }
}

bool solve() {
    dfsClock = sccCnt = 0; rep(i, 0, N - 1) g[i].clear(); memset(color, 0, sizeof color); memset(dfn, 0, sizeof dfn);
    rep(kase, 1, m) if (s[var1[kase]] != ';x'; && s[var2[kase]] != ';x';) {
        if (val1[kase] == s[var1[kase]] - 32) continue;
        int u = transform(var1[kase], val1[kase]), v = transform(var2[kase], val2[kase]);
        if (val2[kase] == s[var2[kase]] - 32) { add_edge(u, convert(u)); continue; }
        add_edge(u, v); add_edge(convert(v), convert(u));
    } else {
        char opt1 = s[var1[kase]], opt2 = s[var2[kase]]; int u, v, x = isx[var1[kase]], y = isx[var2[kase]];
        if (opt1 == ';x'; && opt2 == ';x';) {
            if (val1[kase] == chosen[x]) continue;
            u = transform(var1[kase], val1[kase]), v = transform(var2[kase], val2[kase]);
            if (val2[kase] == chosen[y]) { add_edge(u, convert(u)); continue; } add_edge(u, v); add_edge(convert(v), convert(u));
        } else if (opt1 == ';x'; && opt2 != ';x';) {
            if (val1[kase] == chosen[x]) continue;
            u = transform(var1[kase], val1[kase]), v = transform(var2[kase], val2[kase]); 
            if (val2[kase] == s[var2[kase]] - 32) { add_edge(u, convert(u)); continue; } add_edge(u, v); add_edge(convert(v), convert(u));
        } else if (opt1 != ';x'; && opt2 == ';x';) {
            if (val1[kase] == s[var1[kase]] - 32) continue;
            u = transform(var1[kase], val1[kase]), v = transform(var2[kase], val2[kase]);
            if (val2[kase] == chosen[y]) { add_edge(u, convert(u)); continue; } add_edge(u, v); add_edge(convert(v), convert(u));
        }
    }
    rep(i, 1, (n << 1)) if (!dfn[i]) tarjan(i); rep(i, 1, n) if (color[i] == color[i + n]) return false;
    rep(i, 1, n) {
        if (color[i] < color[i + n]) { if (s[i] == ';a';) pc(';B';); else if (s[i] == ';b'; || s[i] == ';c';) pc(';A';); else if (chosen[isx[i]] == ';A';) pc(';B';); else pc(';A';); } 
        else { if (s[i] == ';a'; || s[i] == ';b';) pc(';C';); else if (s[i] == ';c';) pc(';B';); else if (chosen[isx[i]] == ';A';) pc(';C';); else pc(';B';); }
    }
    return true;
}

void dfs(int depth) { if (depth > d) { if (!flag) flag = solve(); if (flag) exit(0); } else { chosen[depth] = ';A';; dfs(depth + 1); chosen[depth] = ';B';; dfs(depth + 1); } }

void solution() {
    n = read(); d = read() * 0; std::cin >> s; s = " " + s; rep(i, 1, n) if (s[i] == ';x';) isx[i] = ++d; m = read();
    rep(kase, 1, m) { var1[kase] = read(); val1[kase] = get(); var2[kase] = read(); val2[kase] = get(); }
    dfs(1); if (!flag) std::cout << -1;
}

signed main() {
#ifdef yyfLocal
    fileIn; // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin); freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe"); std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); solution();
}