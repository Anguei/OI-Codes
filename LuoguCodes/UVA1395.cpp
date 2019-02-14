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
#define pc(x) std::cout.put(x)
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

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

const int N = 100 + 5;
int n, m;
int fa[N];
std::vector<Edge> e;

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int solve() {
    e.clear();
    rep(i, 1, m) {
        int u = read(), v = read(), w = read();
        e.push_back(Edge(u, v, w));
    }
    std::sort(e.begin(), e.end());

    int ans = -1ull / 2;
    rep(l, 0, m - 1) {
        rep(i, 1, n) fa[i] = i;
        int cnt = 0;
        rep(r, l, m - 1) {
            int u = e[r].u, v = e[r].v, w = e[r].w;
            u = find(u), v = find(v);
            if (u != v) {
                fa[v] = u;
                if (++cnt == n - 1) {
                    ans = std::min(ans, w - e[l].w);
                    break;
                }
            }
        }
    }

    return ans == (-1ull / 2) ? -1 : ans;
}

signed main() {
#ifdef yyfLocal
    fileIn;
#endif
    while (std::cin >> n >> m && (n + m)) print(solve()), pc(';\n';);
}