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
// #define int long long
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

struct Pos {
    int x, y;
    Pos() {}
    Pos(int x, int y) : x(x), y(y) {}
    friend std::ostream& operator << (std::ostream &out, const Pos &pos) {
        out << "(" << pos.x << ", " << pos.y << ")";
        return out;
    }
};

struct State {
    int x, y, dir;
    State() {}
    State(int x, int y, int dir) : x(x), y(y), dir(dir) {}
};

const int N = 20 + 5, inf = 0x7fffffff, dx[] = { -1, 1, 0, 0, 0 }, dy[] = { 0, 0, -1, 1, 0 };
int fBox[N][N][4], fMan[N][N][4], n, m;
char map[N][N];
Pos start, end, startBox, last[N][N];
State pre[N][N][4];

bool valid(int x, int y) { return !(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == ';#';); }

inline int bfs(Pos S, Pos T, Pos B) {
    if (S.x == T.x && S.y == T.y) return 0;
    int dis[N][N]; memset(dis, -1, sizeof dis); dis[S.x][S.y] = 0;
    std::queue<Pos> q; q.push(S);
    while (!q.empty()) {
        Pos u = q.front(); q.pop();
        rep(i, 0, 4) {
            Pos next = Pos(u.x + dx[i], u.y + dy[i]);
            if ((!valid(next.x, next.y)) || (next.x == B.x && next.y == B.y) || (dis[next.x][next.y] != -1))continue;
            dis[next.x][next.y] = dis[u.x][u.y] + 1; last[next.x][next.y] = Pos(u.x, u.y);
            if (next.x == T.x && next.y == T.y) return dis[next.x][next.y]; q.push(next);
        }
    }
    return inf;
}

State BFS() {
    int flag = inf, min = inf;
    std::queue<State> q;
    rep(i, 0, 4) {
        if ((!valid(startBox.x - dx[i], startBox.y - dy[i])) || (!valid(startBox.x + dx[i], startBox.y + dy[i]))) continue;
        State next = State(startBox.x + dx[i], startBox.y + dy[i], i);
        int cnt = bfs(start, Pos(startBox.x - dx[i], startBox.y - dy[i]), startBox); if (cnt == inf) continue;
        fMan[next.x][next.y][next.dir] = cnt + 1; fBox[next.x][next.y][next.dir] = 1; pre[next.x][next.y][next.dir] = State(start.x, start.y, 4); q.push(next);
        if (next.x == end.x && next.y == end.y) flag = 1, min = cnt + 1;
    }
    while (!q.empty()) {
        State u = q.front(); q.pop();
        if (fBox[u.x][u.y][u.dir] == flag) break;
        rep(i, 0, 4) {
            State next = State(u.x + dx[i], u.y + dy[i], i);
            if ((!valid(next.x, next.y)) || (!valid(u.x - dx[i], u.y - dy[i])) || (fBox[next.x][next.y][next.dir] <= fBox[u.x][u.y][u.dir] && fBox[next.x][next.y][next.dir] != -1)) continue;
            int cnt = bfs(Pos(u.x - dx[u.dir], u.y - dy[u.dir]), Pos(u.x - dx[i], u.y - dy[i]), Pos(u.x, u.y)); if (cnt == inf) continue; cnt++;
            if (fMan[next.x][next.y][next.dir] == -1 || fMan[next.x][next.y][next.dir] > fMan[u.x][u.y][u.dir] + cnt) { fMan[next.x][next.y][next.dir] = fMan[u.x][u.y][u.dir] + cnt; pre[next.x][next.y][next.dir] = u; }
            if (fBox[next.x][next.y][next.dir] == -1) { fBox[next.x][next.y][next.dir] = fBox[u.x][u.y][u.dir] + 1; q.push(next); }
            if (next.x == end.x && next.y == end.y) { flag = fBox[next.x][next.y][next.dir]; min = std::min(min, fMan[next.x][next.y][next.dir]); }
        }
    }
    rep(i, 0, 4) if (fMan[end.x][end.y][i] == min) return State(end.x, end.y, i);
    return State(inf, 0, 0);
}

void print2(Pos from, Pos next2) {
    if (from.x == next2.x && from.y == next2.y) return;
    Pos now = last[next2.x][next2.y]; print2(from, now);
    if (now.x == next2.x) pc("we"[next2.y == now.y + 1]); else pc("ns"[next2.x == now.x + 1]);
}

void print(State next) {
    State u = pre[next.x][next.y][next.dir];
    Pos now = Pos(u.x - dx[u.dir], u.y - dy[u.dir]);
    Pos next2 = Pos(next.x - 2 * dx[next.dir], next.y - 2 * dy[next.dir]);
    if (next.dir == 4) return; print(u);
    int cnt = bfs(now, next2, Pos(next.x - dx[next.dir], next.y - dy[next.dir]));
    if (cnt != inf && cnt) print2(now, next2);
    if (u.dir == 4) { if (startBox.x == next.x) pc("WE"[next.y == startBox.y + 1]); else pc("NS"[next.x == startBox.x + 1]); return; }
    if (u.x == next.x) pc("WE"[next.y == u.y + 1]); else pc("NS"[next.x == u.x + 1]);
}

void solution() {
    rep(i, 0, n) scanf("%s", map[i]);
    rep(i, 0, n) rep(j, 0, m) if (map[i][j] == ';S';) start = Pos(i, j); else if (map[i][j] == ';B';) startBox = Pos(i, j); else if (map[i][j] == ';T';) end = Pos(i, j);
    memset(fBox, -1, sizeof fBox); memset(fMan, -1, sizeof fMan);
    State ans = BFS(); if (ans.x == inf) { puts("Impossible."); endln; return; } println(ans); endln;
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
    int kase = 0; while (std::cin >> n >> m && (n + m)) printf("Maze #%d\n", ++kase), solution();
}