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

const int N = 50 + 5;
const int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int a[N][N], color[N][N], area[N * N];
int n, m, colorCnt = 0, max = 0;

bool check(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y, int colorId) {
    color[x][y] = colorId;
    ++area[colorId];
    for (int i = 0; i < 4; ++i) {
        if ((a[x][y] & (1 << i)) == 0) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (!color[dx][dy] && check(dx, dy)) dfs(dx, dy, colorId);
        }
    }
}

void outputN(int ans, int x1, int y1) {
    print(ans), puts(""), print(x1), pc('; ';), print(y1), pc('; ';), puts("N");
}

void outputE(int bns, int x2, int y2) {
    print(bns), puts(""), print(x2), pc('; ';), print(y2), pc('; ';), puts("E");
}

void solve_last() {
    int ans = max, bns = max, x1 = n, x2 = n, y1 = 0, y2 = 0;
    rep(i, 1, n) rep(j, 1, m) {
        if ((a[i][j] & 2) && color[i][j] != color[i - 1][j] && ans <= area[color[i][j]] + area[color[i - 1][j]]) {
            if (ans != area[color[i][j]] + area[color[i - 1][j]]) x1 = i, y1 = j;
            else if (j < y1) x1 = i, y1 = j;
            else if (j == y1 && i > x1) x1 = i;
            ans = area[color[i][j]] + area[color[i - 1][j]];
        }
        if ((a[i][j] & 4) && color[i][j] != color[i][j + 1] && bns <= area[color[i][j]] + area[color[i][j + 1]]) {
            if (bns != area[color[i][j]] + area[color[i][j + 1]]) x2 = i, y2 = j;
            else if (j < y2) x2 = i, y2 = j;
            else if (j == y2 && i > x2) x2 = i;
            bns = area[color[i][j]] + area[color[i][j + 1]];
        }
    }
#define on outputN(ans, x1, y1)
#define oe outputE(bns, x2, y2)
    if (ans > bns) on;//, dbg(1);
    else if (ans < bns) oe;//, dbg(2);
    else if (y1 < y2) on;//, dbg(3);
    else if (y1 > y2) oe;//, dbg(4);
    else if (x1 > x2) on;//, dbg(5);
    else if (x1 < x2) oe;//, dbg(6);
    else on;//, dbg(7);
    //dbg(x1), dbg(x2);
}

void disColor() {
#ifdef yyfLocal
    rep(i, 1, n) {
        rep(j, 1, m) print(color[i][j]), pc('; ';);
        puts("");
    }
#endif
}

void solution() {
    m = read(), n = read();
    rep(i, 1, n) rep(j, 1, m) a[i][j] = read();
    rep(i, 1, n) rep(j, 1, m) if (!color[i][j]) dfs(i, j, ++colorCnt);
    //disColor();
    max = *std::max_element(area + 1, area + colorCnt + 1);
    print(colorCnt), puts(""), print(max), puts("");
    solve_last();
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