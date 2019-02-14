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

const int N = 100000 + 5;
int n, a[N], preSum[N], sufSum[N];

void solution() {
    memset(a, 0, sizeof a);
    memset(preSum, 0, sizeof preSum);
    memset(sufSum, 0, sizeof sufSum);
    n = read();
    rep(i, 1, n) preSum[i] = preSum[i - 1] + (a[i] = read());
    per(i, n, 1) sufSum[i] = sufSum[i + 1] + a[i], sufSum[i + 1] = std::min(sufSum[i + 1], sufSum[i + 2]);
    sufSum[1] = std::min(sufSum[1], sufSum[2]);
    int ans = 0;
    rep(i, 0, n) ans = std::max(ans, preSum[n] - ((preSum[i] + sufSum[i + 1]) << 1));
    print(ans), puts("");
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
    int T = read(); while (T--) solution();
}