// luogu-judger-enable-o2
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
#define int unsigned long long
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
namespace Mker { unsigned long long SA, SB, SC; void init() { SA = read(), SB = read(), SC = read(); } unsigned long long rand() { SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1; unsigned long long t = SA; SA = SB, SB = SC, SC ^= t ^ SA; return SC; } }
struct Matrix {
    int a[2][2];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix operator*(const Matrix &b) const { Matrix res; rep(i, 0, 1) rep(j, 0, 1) res.a[i][j] = (a[i][0] * b.a[0][j] + a[i][1] * b.a[1][j]) % p; return res; }
    // Matrix operator^(int b) const { Matrix a = (*this), res; rep(i, 0, 1) res.a[i][i] = 1;; while (b) { if (b & 1) res = res * a; a = a * a; b >>= 1; } }
    // friend std::ostream &operator<<(std::ostream &out, const Matrix &mat) { out << std::endl << "    "; rep(i, 0, 1) { rep(j, 0, 1) out << mat.a[i][j] << " "; if (i != 1) out << std::endl << "    "; } return out; }
} I, base, powed1[65560], powed2[65560];

void init() {
    rep(i, 0, 1) I.a[i][i] = 1;
    base.a[0][0] = 233, base.a[0][1] = 1, base.a[1][0] = 666, base.a[1][1] = 0;
    powed1[0] = powed2[0] = I; rep(i, 1, 65536) powed1[i] = base * powed1[i - 1]; rep(i, 1, 65536) powed2[i] = powed2[i - 1] * powed1[65536];
}

// int solution() { int n = (Mker::rand() - 1) % (p - 1); return (powed1[n & 65535] * powed2[n >> 16]).a[0][0]; }
void solution() {
    int T = read(), ans = 0; Mker::init(); init(); while (T--) {
        int n = Mker::rand() - 1; n %= p - 1; ans ^= ((powed1[n & 65535] * powed2[n >> 16]).a[0][0]);
    } println(ans);
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
    solution(); // int T = read(), ans = 0; init(); Mker::init(); while (T--) ans ^= solution(); println(ans);
}

// Luogu Ranking Comparator
// Luogu Records Comparator
