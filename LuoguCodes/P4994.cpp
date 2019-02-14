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
#include <numeric>
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

const int mod = 1000000007;

struct Matrix {
    static const int sz = 3;
    int a[3][3];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix operator * (const Matrix &b) {
        Matrix res;
        rep(i, 1, 2) rep(j, 1, 2) rep(k, 1, 2) res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
    Matrix operator ^ (int b) {
        Matrix a = (*this), res;
        rep(i, 1, sz - 1) res.a[i][i] = 1;
        while (b) {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    friend std::ostream &operator << (std::ostream &out, const Matrix &mat) {
        out << std::endl << "    ";
        rep(i, 1, sz - 1) {
            rep(j, 1, sz - 1) out << mat.a[i][j] << " ";
            if (i != sz - 1) out << std::endl << "    ";
        }
        return out;
    }
} base, ans, baseSqr;

void init() {
    base.a[1][1] = 1, base.a[1][2] = 1, base.a[2][1] = 1;
    ans.a[1][1] = 1, ans.a[1][2] = 1;
    rep(i, 1, 2) baseSqr.a[i][i] = 1;
}

void solution() {
    int m = read(), pos = 0;
    int limit = m * m;
    int last1 = 1, last2 = 1;
    rep(i, 3, limit) {
        int ans = last1 + last2; ans %= m;
        int ans2 = ans + last2; ans2 %= m;
        if (ans == 0 && ans2 == 1) { println(i); return; }
        last1 = last2; last2 = ans;
    }
    /*if (m == 2) { puts("3"); return; }
    init();
    rep(i, 3, m * m) {
        baseSqr = baseSqr * base;
        Matrix muled = ans * baseSqr;
        // dbg(baseSqr); dbg(muled);
        if (muled.a[1][1] % m == 0) { pos = i; break; }
    }
    dbg(pos);
    for (int i = pos; i <= m * m; i += pos) {
        Matrix tmp1 = base ^ (i - 2); int f1 = (ans * tmp1).a[1][1] % m;
        Matrix tmp2 = base ^ (i - 1); int f2 = (ans * tmp2).a[1][1] % m;
        // std::clog << f1 << " " << f2 << std::endl; 
        if (f1 == 0 && f2 == 1) { println(i); break; }
    }*/

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