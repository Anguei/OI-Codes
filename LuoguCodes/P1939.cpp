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
#define fn "task"
#define ll long long
#define int long long
#define pc(x) putchar(x)
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

const int mod = 1000000007;
int n;

struct Matrix {
    int a[3][3];
    Matrix () { memset(a, 0, sizeof a); }
    Matrix (int num) { rep(i, 0, 2) rep(j, 0, 2) a[i][j] = (i == j) * num; }
} m;

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2) c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
    return c;
}

Matrix operator ^ (Matrix a, int b) {
    Matrix c(1);
    while (b) {
        if (b & 1) c = c * a;
        a = a * a;
        b >>= 1;
    }
    return c;
}

void init() {
    /*
    1 0 1
    1 0 0
    0 1 0
    */
    m.a[0][0] = 1; m.a[0][1] = 0; m.a[0][2] = 1;
    m.a[1][0] = 1; m.a[1][1] = 0; m.a[1][2] = 0;
    m.a[2][0] = 0; m.a[2][1] = 1; m.a[2][2] = 0;
}

void solution() {
    n = read();
    if (n <= 3) { puts("1"); return; }
    init();
    m = m ^ (n - 3);
    print((m.a[0][0] + m.a[0][1] + m.a[0][2]) % mod), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    int T = read(); while (T--) solution();
}