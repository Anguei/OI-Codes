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
// #define int long long
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
#define fprintf(a, b, c, d) fprintf(a, b, c, d)
#else
#define dbg(x) 42
#define logs(x) 42
#define fprintf(a, b, c, d) 42
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

const int __________ = 20 + 5;
int ___, ____[__________], _____[__________][__________], ______[__________], _______[__________], ________ = 0, _________ = 0;

void solution() {
    ___ = read(); rep(_, 1, ___) ____[_] = read(); rep(_, 1, ___ - 1) rep(__, _ + 1, ___) _____[_][__] = read();
    rep(_, 1, ___) { rep(__, 1, ___) if (_____[__][_] && ______[__] > ______[_]) ______[_] = ______[__], _______[_] = __; ______[_] += ____[_]; if (______[_] > ________) ________ = ______[_], _________ = _; }
    std::vector<int> __________; while (_______[_________]) __________.push_back(_________), _________ = _______[_________]; __________.push_back(_________); std::reverse(__________.begin(), __________.end()); for (auto _ : __________) print(_), pc('; ';); endln; println(________);
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