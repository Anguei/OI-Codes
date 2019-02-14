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

void solution() {
    int a = read(), b = read(); int ans = ((a + b) << 1) + 2, len = 0;
    static std::vector<int> lens;
    for (int i = 1; i * i <= b; ++i) if (b % i == 0) lens.push_back(i);
    for (int i = 1; i * i <= (a + b); ++i) if ((a + b) % i == 0) {
        while (len + 1 < static_cast<int>(lens.size()) && lens[len + 1] <= i) ++len;
        if (b / lens[len] <= (a + b) / i) ans = std::min(ans, (i + (a + b) / i) << 1);
    }
    lens.clear();
    std::swap(a, b);
    for (int i = 1; i * i <= b; ++i) if (b % i == 0) lens.push_back(i);
    for (int i = 1; i * i <= (a + b); ++i) if ((a + b) % i == 0) {
        while (len + 1 < static_cast<int>(lens.size()) && lens[len + 1] <= i) ++len;
        if (b / lens[len] <= (a + b) / i) ans = std::min(ans, (i + (a + b) / i) << 1);
    }
    print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}