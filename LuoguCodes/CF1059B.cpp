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
// #define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a) for (int i = 0; i < (a); ++i)
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

const int N = 1000 + 5;
int n, m;
char map[N][N];
bool vis[N][N];

bool in(int i, int j) {
    return (i >= 1 && i <= n - 2 && j >= 1 && j <= m - 2);
}

bool isc(int i, int j) {
    for (int x = i; x < i + 3; ++x) for (int y = j; y < j + 3; ++y)
        if (x == i + 1 && y == j + 1) continue;
        else if (map[x][y] != ';#';) return false;
    return true;
}

void print(int i, int j) {
    --i, --j;
    for (int x = i; x < i + 3; ++x) for (int y = j; y < j + 3; ++y)
        if (x == i + 1 && y == j + 1) continue;
        else vis[x][y] = false;
}

int solution() {
    n = read(), m = read();
    rep(i, n) {
        scanf("%s", map[i]);
        rep(j, m) if (map[i][j] == ';#';) vis[i][j] = true;        
    }
    rep(i, n - 2) rep(j, m - 2) if (in(i + 1, j + 1) && isc(i, j)) print(i + 1, j + 1);
    rep(i, n) rep(j, m) if (vis[i][j]) return puts("NO"), 0; return puts("YES"), 0;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}