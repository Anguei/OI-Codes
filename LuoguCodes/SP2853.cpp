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

const int N = 80 + 5;
int n, m, p[N], p2[N][N];

void solution() {
    rep(i, 0, n) p[i] = read() - 1;
    std::string s; std::getline(std::cin, s); std::string t(s.size(), 0);
    rep(i, 0, n) p2[0][i] = p[i];
    rep(i, 1, 30) rep(j, 0, n) p2[i][j] = p2[i - 1][p2[i - 1][j]];
    per(i, 30, 0) if (m & (1 << i)) {
        rep(j, 0, n) t[p2[i][j]] = s[j];
        rep(j, 0, n) s[j] = t[j];
    }
    std::cout << s << std::endl;
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
    while (std::cin >> n >> m && n && m) solution();
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}