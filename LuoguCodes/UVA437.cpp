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

#define _3i (3 * i)
#define _3n (3 * n)

struct Cube {
    int x, y, z;
    Cube(int x, int y, int z) : x(x), y(y), z(z) {}
    Cube() = default;
    bool operator < (const Cube &rhs) const {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};

const int N = 30 + 5;
int n, kase = 0, ans = 0, size[4], dp[3 * N];
Cube c[3 * N];

void clear() {
    ans = 0;
    memset(dp, 0, sizeof dp);
}

bool check(int a, int b) {
    return c[a].x > c[b].x && c[a].y > c[b].y;
}

int solve() {
    clear();
    rep(i, 0, n-1) { // sillyBug: rep(i, 1, n)
        rep(j, 1, 3) size[j] = read();
        std::sort(size + 1, size + 4);
        c[_3i + 1].x = size[1], c[_3i + 1].y = size[2], c[_3i + 1].z = size[3];
        c[_3i + 2].x = size[1], c[_3i + 2].y = size[3], c[_3i + 2].z = size[2];
        c[_3i + 3].x = size[2], c[_3i + 3].y = size[3], c[_3i + 3].z = size[1];
    }
    std::sort(c + 1, c + _3n + 1);
    rep(i, 1, _3n) dp[i] = c[i].z;
    rep(i, 2, _3n) rep(j, 1, i - 1) if (check(i, j)) dp[i] = std::max(dp[i], dp[j] + c[i].z);
    rep(i, 1, _3n) ans = std::max(ans, dp[i]);
    return ans;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#endif
    while (std::cin >> n && n) printf("Case %d: maximum height = %d\n", ++kase, solve());
}