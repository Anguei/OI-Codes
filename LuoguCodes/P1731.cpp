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
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
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

const int M = 15 + 5;
int n, m, ans = -1ull / 2, h[M], r[M];

void dfs(int x = 1, int y = n, int k = 0, int z = m) {
    if (y < 0 || x > m + 1 || k >= ans) return;
    if (!y && x == m + 1) { k += r[1] * r[1]; ans = std::min(ans, k); return; }
    if (k + z + r[1] * r[1] > ans) return;
    if (y - r[x - 1] * r[x - 1] * h[x - 1] * z > 0) return;
    per(i, r[x - 1] - 1, z) per(j, h[x - 1] - 1, z) if (y - i * i * j >= 0 && x<= m) {
        r[x] = i, h[x] = j;
        dfs(x + 1, y - i * i * j, k + (i * 2 * j), z - 1);
        r[x] = h[x] = 0;
    }
}

void solution() {
    n = read(), m = read();
    h[0] = r[0] = sqrt(n);
    dfs();
    print(ans == (-1ull / 2) ? 0 : ans), endln;
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
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}