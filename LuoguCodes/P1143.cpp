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

int qpow(int a, int b) {
    int res = 1; while (b) {
        if (b & 1) res *= a; a *= a; b >>= 1;
    } return res;
}

void solution() {
    int n = read(); std::string s; std::cin >> s; int base = read(); dbg(s); std::reverse(s.begin(), s.end());
    int num = 0; for (int i = 0; i < static_cast<int>(s.size()); ++i) num += isdigit(s[i]) ? (s[i] - 48) * qpow(n, i) : (s[i] - 55) * qpow(n, i); dbg(num);
    std::stack<char> stk; while (num) { stk.push(num % base > 10 ? 55 + num % base : 48 + num % base); num /= base; } while (!stk.empty()) pc(stk.top()), stk.pop();
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
}