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

int n, m, k, half, ans = 0;
int a[25][25];
std::map<int, int> map[25][25];

void dfs1(int x = 1, int y = 1, int val = 0, int depth = 0) {
    if (x > n || y > m) return;
    val ^= a[x][y];
    if (x + y == half) { ++map[x][y][val]; return; }
    dfs1(x + 1, y, val, depth + 1); dfs1(x, y + 1, val, depth + 1);
}

void dfs2(int x = n, int y = m, int val = 0, int depth = 0) {
    if (x < 1 || y < 1) return;
    if (x + y == half) { ans += map[x][y][k ^ val]; return; }
    val ^= a[x][y];
    dfs2(x - 1, y, val, depth + 1); dfs2(x, y - 1, val, depth + 1);
}

void solution() {
    n = read(), m = read(), k = read(); half = (n + m + 2) >> 1;
    rep(i, 1, n) rep(j, 1, m) a[i][j] = read();
    dfs1(); dfs2();
    print(ans), puts("");
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