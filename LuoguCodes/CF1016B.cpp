#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) ;
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

int n, m, q;
std::string s, t; 

bool check(int now, int depth) {
    if (depth == m) return true;
    if (s[now] == t[depth]) return check(now + 1, depth + 1);
    return false;
}

signed main() {
    n = read(), m = read(), q = read();
    std::cin >> s >> t;
    //dbg(s); dbg(t);
    //std::map<int, bool> map;
    bool map[1005] = { 0 };
    rep(i, 0, n - m) if (s[i] == t[0] && check(i + 1, 1)) map[i] = true;
    while (q--) {
        int l = read(), r = read(), ans = 0;
        rep(i, l - 1, r - m) ans += map[i];
        print(ans), puts("");
    }
}