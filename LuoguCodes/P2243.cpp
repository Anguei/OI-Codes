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
#define fn "2632"
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

const int N = 500 + 5;
const int dir[4][2] = { {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
int n, m, dis[N][N], inq[N][N];
bool map[N][N];
char in[N][N];
std::deque<std::pair<std::pair<int, int>, std::pair<int, int>>> dq;

bool len(int newX, int oldX, int newY, int oldY) { return ((oldX < newX && oldY < newY) || (oldX > newX && oldY > newY)) ^ map[std::min(newX, oldX)][std::min(newY, oldY)]; }

bool valid(int x, int y) { return x >= 1 && y >= 1 && x <= n + 1 && y <= m + 1; }

void bfs() {
    dq.push_back(std::make_pair(std::make_pair(0, 0), std::make_pair(1, 1)));
    while (!dq.empty()) {
        auto front = dq.front(); dq.pop_front(); auto u = front.first, v = front.second; int oldX = u.first, oldY = u.second, newX = v.first, newY = v.second; 
        if (inq[newX][newY]) continue; dis[newX][newY] = dis[oldX][oldY] + len(newX, oldX, newY, oldY); inq[newX][newY] = true;
        rep(i, 0, 3) {
            int newU = newX + dir[i][0], newV = newY + dir[i][1]; auto s = std::make_pair(newU, newV);
            if (!inq[newU][newV] && valid(newU, newV)) if (len(newU, newX, newV, newY)) dq.push_back(std::make_pair(v, s)); else dq.push_front(std::make_pair(v, s));
        }
    }
}

void solution() {
    memset(dis, 0, sizeof dis); memset(map, 0, sizeof map); memset(in, 0, sizeof in); memset(inq, false, sizeof inq);
    n = read(), m = read();
    if ((n + m) & 1) { puts("NO SOLUTION"); return; }
    rep(i, 1, n) {
        scanf("%s", in[i] + 1);
        rep(j, 1, m) map[i][j] = (in[i][j] == ';\\';);
    }
    map[0][0] = 1; bfs(); println(dis[n + 1][m + 1]);
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
    int T = read(); while (T--) solution();
}

// 这是 P2243 还是 P4667？记得处理了吗？