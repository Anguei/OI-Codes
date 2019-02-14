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
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
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

const int N = 1000 + 5;
int m, n, k, l, d;
struct Path
{
    int pos, tot;
} line[N], col[N];

int solution()
{
    m = read(), n = read(), k = read(), l = read(), d = read();
    rep(i, 1, n) line[i].pos = i;
    rep(i, 1, m) col[i].pos = i;
    rep(i, 1, d)
    {
        int x = read(), y = read(), p = read(), q = read();
        if (x > p)
            ++line[p].tot;
        if (p > x)
            ++line[x].tot;
        if (y > q)
            ++col[q].tot;
        if (q > y)
            ++col[y].tot;
    }
    std::sort(line + 1, line + n + 1, [](const Path &p1, const Path &p2) { return p1.tot > p2.tot; });
    std::sort(line + 1, line + k + 1, [](const Path &p1, const Path &p2) { return p1.pos < p2.pos; });
    rep(i, 1, k) print(line[i].pos), pc('; ';);
    puts("");
    std::sort(col + 1, col + n + 1, [](const Path &p1, const Path &p2) { return p1.tot > p2.tot; });
    std::sort(col + 1, col + l + 1, [](const Path &p1, const Path &p2) { return p1.pos < p2.pos; });
    rep(i, 1, l) print(col[i].pos), pc('; ';);
    puts("");
    return 0;
}

signed main()
{
#ifdef yyfLocal
    //fileIn;
    //fileOut;
#else
#ifndef ONLINE_JUDGE
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    solution();
}