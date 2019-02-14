// luogu-judger-enable-o2
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
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
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

const int N = 100 + 5;
int a[N], b[N], l[N], n, m, dp[25000 + 5];

bool canExpress(int pos) {
    if (pos == 1) return false;
    int x = a[pos];
    rep(i, 1, m) if (x % b[i] == 0) return true;
    rep(i, 1, m) l[i] = x / b[i];
    
return false;
}

void solution() {
    m = 0; memset(dp, 0, sizeof dp); dp[0] = 1;
    n = read(); rep(i, 1, n) a[i] = read(); std::sort(a + 1, a + n + 1);
    rep(i, 1, n) if (!dp[a[i]]) {
        ++m;
        rep(j, a[i], a[n]) if (dp[j - a[i]]) dp[j] = 1;
    }
    println(m);
#ifdef yyfLocal
    // rep(i, 1, m) std::clog << b[i] << " "; std::clog << std::endl;
#endif
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