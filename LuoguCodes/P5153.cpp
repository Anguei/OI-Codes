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

const int p = 1e9 + 7.5;
const int table[] = { 0, 6, 420, 360360, 72201776446800ll };
int n, a, b, c;

int qpow(int a, int b) {
    int res = 1; while (b) {
        if (b & 1) (res *= a) %= p;
        (a *= a) %= p; b >>= 1;
    } return res;
}

void solution() {
    n = read();
    a = (n + 1) / 2 - 1;
    b = (1 + n / table[1]) / 2 + (n / table[2] + 1) / 2 + (n / table[3] + 1) / 2 + (1 + n / table[4]) / 2;
    c = n / 2 - 1 - b;
    println(qpow(2, a) * qpow(3, c) % p * qpow(4, b) % p);
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}

// Luogu Ranking Comparator
// Luogu Records Comparator
