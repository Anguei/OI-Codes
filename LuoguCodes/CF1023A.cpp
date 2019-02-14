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

signed main() {
    int n = read(), m = read();
    if (n > m + 1) return puts("NO"), 0;
    std::string s, t; 
    std::cin >> s >> t;
    int star = 0;
    for (auto i : s) if (i == ';*';) star = 1;
    if (!star && s != t) return puts("NO");
    std::string pre = s.substr(0, s.find(';*';)), suf = s.substr(s.find(';*';) + 1);
    int pres = pre.size(), sufs = suf.size();
    if (t.substr(0, pres) == pre && t.substr(m - sufs) == suf) puts("YES");
    else puts("NO");
}