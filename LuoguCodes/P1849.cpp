// luogu-judger-enable-o2
// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
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

const int N = 1000 + 5;
const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int map[N][N], dis[N][N], inq[N][N];
int n, sx, sy, maxSize = 0;

struct Pos{
    int x, y;
    Pos() = default;
    Pos(int x, int y) : x(x), y(y) {}
    bool operator < (const Pos &rhs) const {
        return x < rhs.x || y < rhs.y;
    }
};

//std::priority_queue<Pos> pq;
std::queue<Pos> q;

bool inMap(int x, int y) {
    return x >= 0 && y >= 0 && x <= 1001 && y <= 1001;
}

void spfa(int sx, int sy) {
    memset(dis, 0x3f, sizeof dis);
    q.push(Pos(sx, sy));
    inq[sx][sy] = true;
    dis[sx][sy] = 0;
    
    while (!q.empty()) {
        //dbg(q.size());
        //maxSize = std::max(static_cast<unsigned>(maxSize), q.size());
        auto top = q.front(); q.pop();
        inq[top.x][top.y] = false;
        for (int i = 0; i < 4; ++i) {
            int dx = top.x + dir[i][0], dy = top.y + dir[i][1];
            if (!inMap(dx, dy)) continue;
			if (dis[top.x][top.y] + map[dx][dy] < dis[dx][dy]) {
                inq[dx][dy] = false;
                dis[dx][dy] = dis[top.x][top.y] + map[dx][dy];
                if (!inq[dx][dy]) {
                    q.push(Pos(dx, dy));
                    inq[dx][dy] = true;
                }
            }
        }
    }
}

void solution() {
    n = read(), sx = read(), sy = read();
    rep(i, 1, n) {
        int x = read(), y = read();
        map[x][y] = 1;
    }
    spfa(sx, sy);
    print(dis[0][0]), puts("");
    dbg(maxSize);
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
