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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x " = " << (x) << std::endl
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

struct Pos {
    int x, y;
    Pos() = default;
    Pos(int _x, int _y) : x(_x), y(_y) {}
};

const int N = 1000 + 5;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, joeX, joeY, ans = -1ull / 2;
char map[N][N];
int reachedTime[N][N][2];
bool reachable[N][N][2];
std::queue<Pos> q;

void bfs(int who)
{
    // who: 0 for Joe, 1 for fire
    while (!q.empty()) {
        auto front = q.front(); q.pop(); int x = front.x, y = front.y;
        for (int i = 0; i < 4; ++i) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 1 && dy >= 1 && dx <= n && dy <= m && map[dx][dy] == ';.'; && !reachable[dx][dy][who]) {
                q.push(Pos(dx, dy));
                reachable[dx][dy][who] = true;
                reachedTime[dx][dy][who] = reachedTime[x][y][who] + 1;
            }
        }
    }
}

void walk(int x, int y) { 
    if (map[x][y] == ';.'; && reachable[x][y][0] && (!reachable[x][y][1] || reachedTime[x][y][0] < reachedTime[x][y][1])) ans = std::min(ans, reachedTime[x][y][0] + 1); 
}

void solve() {
    ans = -1ull / 2; memset(reachable, false, sizeof reachable); 
    n = read(), m = read(); 
    rep(i, 1, n) scanf("%s", map[i] + 1);
    rep(i, 1, n) rep(j, 1, m)  if (map[i][j] == ';J';) joeX = i, joeY = j, map[i][j] = ';.';; 
    std::vector<Pos> fire; rep(i, 1, n) rep(j, 1, m) if (map[i][j] == ';F';) fire.push_back(Pos(i, j));
    reachable[joeX][joeY][0] = true; reachedTime[joeX][joeY][0] = 0; q.push(Pos(joeX, joeY)); bfs(0); // bfs for Joe
    for (const auto &i : fire) reachable[i.x][i.y][1] = true, reachedTime[i.x][i.y][1] = 0, q.push(i); bfs(1); // bfs for fire
    rep(i, 1, n) walk(i, 1), walk(i, m); rep(j, 1, m) walk(1, j), walk(n, j);
    if (ans == -1ull / 2) puts("IMPOSSIBLE"); else print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    freopen("testdata.in", "r", stdin);
    freopen("testdata.out", "w", stdout);
#endif
    int T = read(); while (T--) solve();
}