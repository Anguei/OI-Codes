// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 用老婆代码交 P3110
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
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x " = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read()
{
    int res = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == ';-';)
            flag = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x)
{
    if (x < 0)
        putchar(';-';), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + 48);
}

const int N = 40000 + 5;
int b, e, p, n, m;
int disB[N], disE[N], disP[N];
bool inq[N];
std::queue<int> q;
std::vector<int> g[N];

void spfa(int s, int *dis) {
    while (!q.empty()) q.pop(); rep(i, 1, N) dis[i] = -1ull / 4;
    q.push(s); inq[s] = true; dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (auto v : g[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
}

signed main()
{
    b = read(), e = read(), p = read(), n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    spfa(1, disB); spfa(2, disE); spfa(n, disP);
    int ans = -1ull / 2;
    rep(i, 1, n) ans = std::min(ans, b * disB[i] + e * disE[i] + p * disP[i]);
    print(ans), puts("");
}