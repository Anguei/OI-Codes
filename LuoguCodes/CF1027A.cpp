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
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, b, a) for (register int i = (b); i >= (a); --i)
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

int solve() {
    int  n = read();
    std::string s; std::cin >> s;
    std::string s2(s); std::reverse(s2.begin(), s2.end());
    if (s == s2) return puts("YES"), 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        char ch1 = s[i], ch2 = s[n - i - 1];
        if (std::abs(ch1 - ch2) > 2 || std::abs(ch1 - ch2) == 1) flag = false;
    }
    return puts(flag ? "YES" : "NO"), 0;
}

signed main() {
#ifdef yyfLocal
    fileIn;
#endif
    int T = read(); while (T--) solve();
}

// fuck UKE