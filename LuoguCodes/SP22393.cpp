#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
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

struct Node {
    int x, y;
    Node() {}
    Node(int x, int y) : x(x), y(y) {}
};

const int N = 1000 + 5, dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
char map[N][N];
int dis[N][N], n, m;
bool vis[N][N];

std::deque<Node> dq;
void bfs() {
    dis[1][1] = 0; dq.push_front(Node(1, 1));
    while (!dq.empty()) {
        const Node front = dq.front(); dq.pop_front(); int x = front.x, y = front.y; // std::clog << x << " " << y << " " << dis[x][y] << std::endl;
        rep(i, 0, 3) {
            int dx = x + dir[i][0], dy = y + dir[i][1]; if (dx < 1 || dy < 1 || dx > n || dy > m) continue; int w = (map[dx][dy] != map[x][y]);
            if (dis[dx][dy] > dis[x][y] + w) dis[dx][dy] = dis[x][y] + w, w ? dq.push_back(Node(dx, dy)) : dq.push_front(Node(dx, dy));
        }
    }
}

void solution() {
    n = read(); m = read(); memset(dis, 0x3f, sizeof dis); memset(vis, 0, sizeof vis);
    rep(i, 1, n) scanf("%s", map[i] + 1); bfs(); println(dis[n][m]);
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    int Q = read(); while (Q--) solution();
}