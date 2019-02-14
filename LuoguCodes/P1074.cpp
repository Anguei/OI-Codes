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
#define fn "2591"
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

struct Data {
    int begin, zeroCnt;
    Data() {}
    Data(int begin, int zeroCnt) : begin(begin), zeroCnt(zeroCnt) {}
    bool operator < (const Data &rhs) const { return zeroCnt < rhs.zeroCnt; }
};

const int N = 10, n = 9;
int map[N][N], s[N * N][4], decided = 0, u = 0, ans = -0x7fffffff;
bool line[N][N], col[N][N], gong[N][N];
Data cou[N];

int getGongId(int x, int y) { return (x - 1) / 3 * 3 + (y - 1) / 3 + 1; }
int pts(int x, int y) { if (x == 1 || y == 1 || x == 9 || y == 9) return 6; if (x == 2 || y == 2 || x == 8 || y == 8) return 7; if (x == 3 || y == 3 || x == 7 || y == 7) return 8; if (x == 4 || y == 4 || x == 6 || y == 6) return 9; return 10; }

void dfs(int p, int now) {
    if (p == u) { ans = std::max(ans, now); return; }
    rep(i, 1, n) if (!line[s[p][0]][i] && !col[s[p][1]][i] && !gong[s[p][3]][i]) {
        line[s[p][0]][i] = col[s[p][1]][i] = gong[s[p][3]][i] = true;
        dfs(p + 1, now + (s[p][2] * i));
        line[s[p][0]][i] = col[s[p][1]][i] = gong[s[p][3]][i] = false;
    }
}

void solution() {
    rep(i, 1, n) cou[i].begin = i;    
    rep(i, 1, n) rep(j, 1, n) {
        map[i][j] = read();
        if (map[i][j]) line[i][map[i][j]] = col[j][map[i][j]] = gong[getGongId(i, j)][map[i][j]] = true, decided += map[i][j] * pts(i, j);
        else ++cou[i].zeroCnt;
    }
    std::sort(cou + 1, cou + n + 1);
    rep(i, 1, n) rep(j, 1, n) if (map[cou[i].begin][j] == 0) s[u][0] = cou[i].begin, s[u][1] = j, s[u][2] = pts(cou[i].begin, j), s[u++][3] = getGongId(cou[i].begin, j);
    dfs(0, decided); println(ans > 0 ? ans : -1);
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