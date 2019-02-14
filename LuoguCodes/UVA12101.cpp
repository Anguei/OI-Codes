// 一定要开启 Fiddler
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
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
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

int a, b, ans, digit[500];
bool vis[10005];
std::queue<std::pair<int, int> > q;

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
    return true;
}

int solve() {
    memset(vis, false, sizeof vis); memset(digit, 0, sizeof digit);
    a = read(), b = read(); ans = -1ull / 2;
    if (a == b) return puts("0"), 0;
    q.push(std::make_pair(a, 0)); vis[a] = true;
    while (!q.empty()) {
        std::pair<int, int> x = q.front(); q.pop();
        if (x.first == b) {
            ans = std::min(ans, x.second);
            continue;
        }
        digit[1] = x.first / 1000; digit[2] = x.first / 100 % 10; digit[3] = x.first / 10 % 10; digit[4] = x.first % 10;
        rep(i, 1, 4) rep(j, 0, 9) {
            if (i == 1 && j == 0) continue;
            int tmp = digit[i]; digit[i] = j;
            int newNumber = digit[1] * 1000 + digit[2] * 100 + digit[3] * 10 + digit[4];
            if (is_prime(newNumber) && !vis[newNumber]) q.push(std::make_pair(newNumber, x.second + 1)), vis[newNumber] = true;
            digit[i] = tmp;
        }
    }
    if (ans != -1ull / 2) return print(ans), puts(""), 0;
    else return puts("Impossible"), 0;
}

signed main() {
    int T = read(); while (T--) solve();
}