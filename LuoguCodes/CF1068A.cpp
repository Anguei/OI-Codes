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

const int N = 200000 + 5;
int a[N], b[N];

void solution() {
    int n = read(), m = read(), k = read(), l = read();
    int ans = (k + l) / m + ((k + l) % m != 0);
    if (ans * m <= n && n >= (k + l)) print(ans), endln;
    else print(-1), endln;
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