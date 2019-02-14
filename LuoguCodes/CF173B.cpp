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
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
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
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m, dis[N][N][4];
char map[N][N];
bool vis[N][N][4];
std::deque<int> dq;

void addFront(int x, int y, int dire, int d) {
    if (d < dis[x][y][dire]) {
        dis[x][y][dire] = d;
        dq.push_front(dire); dq.push_front(y); dq.push_front(x);
    }
}

void addBack(int x, int y, int dire, int d) {
    if (d < dis[x][y][dire]) {
        dis[x][y][dire] = d;
        dq.push_back(x); dq.push_back(y); dq.push_back(dire);
    }
}

void solution() {
    n = read(), m = read();
    rep(i, 0, n) rep(j, 0, m) rep(k, 0, 4) dis[i][j][k] = 0x7fffffff;
    rep(i, 0, n) scanf("%s", map[i]);
    addFront(n - 1, m - 1, 3, 0);
    while (!dq.empty()) {
        int x = dq[0], y = dq[1], dire = dq[2]; rep(i, 0, 3) dq.pop_front(); // std::clog << x << " " << y << " " << dire << std::endl;
        if (vis[x][y][dire]) continue; vis[x][y][dire] = true;
        int d = dis[x][y][dire], dx = x + dir[dire][0], dy = y + dir[dire][1];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m) addFront(dx, dy, dire, d);
        if (map[x][y] == ';#';) rep(i, 0, 4) if (i != dire) addBack(x, y, i, d + 1);
    }
    println(dis[0][0][3] == 0x7fffffff ? -1 : dis[0][0][3]);
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
    logs("main.exe");
    solution();
}