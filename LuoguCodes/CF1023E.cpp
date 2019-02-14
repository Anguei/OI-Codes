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

bool ask(int x, int y, int n, int m) {
    std::cout << "? " << x << " " << y << " " << n << " " << m << std::endl;
    std::string s; std::cin >> s;
    return s[0] == ';Y';;
}

signed main() {
    int n, x = 1, y = 1;
    std::cin >> n;
    std::string s1, s2;
    for (int i = 0; i < n - 1; ++i) {
        if (y < n && ask(x, y + 1, n, n)) {
            ++y; s1.push_back(';R';);
        } else {
            ++x; s1.push_back(';D';);
        }
    }
    x = n; y = n;
    for (int i = 0; i < n - 1; ++i) {
        if (x > 1 && ask(1, 1, x - 1, y)) {
            --x; s2.push_back(';D';);
        } else {
            --y; s2.push_back(';R';);
        }
    }
    std::reverse(s2.begin(), s2.end());
    std::cout << "! " << s1 + s2 << std::endl;
}