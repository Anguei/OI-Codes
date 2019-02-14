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

int n, m, dfsClock = 0, sccCnt = 0;
int low[26], dfn[26], color[26], ind[26];
bool ins[26];;
std::stack<int> stk;
std::vector<int> g[26];
std::set<int> chars, sons[26];
std::vector<std::pair<int, int>> inputed;

void clear() {
    dfsClock = sccCnt = 0;
    chars.clear();
    inputed.clear();
    for (int i = 0; i < 26; ++i) g[i].clear();
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
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

std::string topo() {
    std::string res;
    std::queue<int> q;

    memset(ind, 0, sizeof ind);
    for (int i = 0; i < 26; ++i) for (const auto &j : g[i]) ++ind[j];
    for (int i = 0; i < 26; ++i) if (!ind[i] && chars.count(i)) q.push(i), res += i + 65;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const auto &v : g[u]) if (!--ind[v]) q.push(v), res += v + 65;
    }

    return res;
}

void solution() {
    clear();

    int pos = 0;
    std::string ans;

    for (int i = 0; i < m; ++i) {
        std::string line;
        std::cin >> line;
        int a = line.front() - 65, b = line.back() - 65;
        inputed.push_back(std::make_pair(a, b));
    }

    for (int i = 0; i < m; ++i) {
        const auto &now = inputed[i];
        int a = now.first, b = now.second;
        if (a == b) {
            printf("Inconsistency found after %d relations.\n", i + 1);
            return;
        }
        chars.insert(a), chars.insert(b);
        g[a].push_back(b); // sons[a].insert(b);

        dfsClock = sccCnt = 0;
        memset(low, 0, sizeof low); memset(dfn, 0, sizeof dfn); memset(color, 0, sizeof color);
        for (unsigned i = 0; i < 26; ++i) if (!dfn[i] && chars.count(i)) tarjan(i);
        //dbg(sccCnt);
        if (static_cast<unsigned>(sccCnt) < chars.size()) {
            printf("Inconsistency found after %d relations.\n", i + 1);
            return;
        }

        if (chars.size() == static_cast<unsigned>(n)) {
            ans = ans.empty() ? topo() : ans;
            pos = pos ? pos : i;
        }
    }

    if (ans.empty()) std::cout << "Sorted sequence cannot be determined." << std::endl;
    else printf("Sorted sequence determined after %d relations: %s.\n", pos + 1, ans.data());
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
    while (std::cin >> n >> m) solution();
}




/*// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
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

int n, m;
int ind[26];
std::set<int> chars, sons[26];
std::vector<int> name1s, name2s;
std::vector<int> g[26];

void clear() {
    chars.clear();
    name1s.clear();
    name2s.clear();
    for (int i = 0; i < 26; ++i) sons[i].clear(), g[i].clear(), ind[i] = 0;
}

std::string topo(const std::vector<int> g[]) {
    std::string res;

    std::queue<int> q;
    for (int i = 0; i < 26; ++i) for (const auto &v : sons[i]) ++ind[v];
    //for (int i = 0; i < 26; ++i) dbg(ind[i]);
    for (int i = 0; i < 26; ++i) if (!ind[i] && chars.count(i)) q.push(i), res += i + 65; // pc(i + 65);
    while (!q.empty()) {
        int u = q.front(); q.pop(); 
        for (const auto &v : g[u]) {
            if (!--ind[v]) q.push(v), res += v + 65; //pc(v + 65);
        }
    }

    return res;
}

bool dfs(int son, int target) {
    if (son == target) return true;
    for (const auto &v : g[son]) return dfs(v, target);
    return false;
}

namespace Tarjan {
    const int N = 30;
    int low[N], dfn[N], size[N], color[N], sccCnt = 0, dfsClock = 0;
    bool ins[N];
    std::stack<int> stk;

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

    bool main() {
        sccCnt = dfsClock = 0;
        memset(low, 0, sizeof low);
        memset(dfn, 0, sizeof dfn);
        memset(size, 0, sizeof size);
        memset(color, 0, sizeof color);

        rep(i, 0, chars.size() - 1) if (!dfn[i]) tarjan(i);

        //dbg(sccCnt); dbg(chars.size());
        return sccCnt < chars.size();
    }
}

void solution() {
    clear();
    
    rep(i, 1, m) {
        std::string s; std::cin >> s;
        int name1 = s[0] - 65, name2 = s[2] - 65;
        name1s.push_back(name1), name2s.push_back(name2);
    }

    int ans = 0;
    std::string str;
    
    for (int i = 0; i < m; ++i) {
        int name1 = name1s[i], name2 = name2s[i];
        g[name1].push_back(name2); sons[name1].insert(name2);
        chars.insert(name1); chars.insert(name2);
        //for (const auto &v : sons[name1]) if (dfs(v, name1)) { // if (sons[v].count(name1)) {
        if (Tarjan::main()) {
            printf("Inconsistency found after %d relations.\n", i + 1);
            return;
        }
        if (chars.size() == static_cast<unsigned>(n)) {
            str = str.empty() ? topo(g) : str;
            ans = ans ? ans : i;
        }
    }
    
    //if (chars.size() <= static_cast<unsigned>(n)) {
        //puts("Sorted sequence cannot be determined.");
        //return;
    //}
    if (!ans) {
        puts("Sorted sequence cannot be determined.");
    } else {
        printf("Sorted sequence determined after %d relations: ", ans + 1);
        std::cout << str << "." << std::endl;
    }
    
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
    while (std::cin >> n >> m) solution();
}*/