// luogu-judger-enable-o2
/*#ifdef yyfLocal
#include <Windows.h>
#endif
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
#define fn "4887"
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

int n, m, t, tot;

struct Matrix {
    static const int N = 300 + 5, mod = 2017;
    int a[N][N];
    Matrix() { memset(a, 0, sizeof a); }

    Matrix operator*(const Matrix &b) {
        rep(i, 1, 1000) std::clog << "************" << std::endl;
        Matrix res;
        rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) res.a[i][j] = ((res.a[i][j] + a[i][k] * b.a[k][j] % mod) + mod) % mod;
        return res;
    }

    Matrix operator^(int b) {
        rep(i, 1, 1000) std::clog << "^^^^^^^^^^^^" << std::endl;
        Matrix a = (*this), res;
        dbg(n);
        rep(i, 1, n) res.a[i][i] = 1;
        while (b) {
            dbg(b);
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

#ifdef yyfLocal
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
        out << std::endl << "    ";
        rep(i, 1, n) {
            rep(j, 1, n) print(mat.a[i][j]), pc('; ';); 
            if (i != n) { endln; rep(i, 1, 4) pc('; ';); }
        }
        return out;
    }
#endif
} map, ans;

Matrix mpow(Matrix a, int b) {
    Matrix res; rep(i, 1, n) res.a[i][i] = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solution() {
    n = read(), m = read();
    while (m--) { int u = read(), v = read(); map.a[u][v] = map.a[v][u] = 1; }
    rep(i, 0, n) map.a[i][i] = map.a[i][0] = 1;
    t = read(); dbg(t); ans = mpow(map, t); logs("powed"); 
    rep(i, 0, n) tot += ans.a[1][i], tot %= 2017; println(tot);
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
}*/
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
#define fn "4887"
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

int n, m, t, tot = 0;

struct Matrix {
    static const int N = 30 + 5, mod = 2017;
    int a[N][N];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix operator*(const Matrix &b) {
        Matrix res;
        rep(i, 0, n + 1) rep(j, 0, n + 1) rep(k, 0, n + 1) res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
    Matrix operator^(int b) {
        Matrix a = (*this), res; rep(i, 0, n + 1) res.a[i][i] = 1;
        while (b) {
            if (b & 1) res = res * a;
            a = a * a; b >>= 1;
        }
        return res;
    }
#ifdef yyfLocal
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
        out << std::endl << "    ";
        rep(i, 0, n + 1) {
            rep(j, 0, n + 1) print(mat.a[i][j]), pc('; ';); 
            if (i != n + 1) { endln; rep(i, 1, 4) pc('; ';); }
        }
        return out;
    }
#endif
} map;

void solution() {
    n = read(), m = read(); while (m--) { int u = read(), v = read(); map.a[u][v] = map.a[v][u] = 1; }
    rep(i, 0, n) map.a[i][i] = map.a[i][0] = 1;
    t = read(); Matrix ans = map ^ t; dbg(ans); rep(i, 0, n + 1) (tot += ans.a[1][i - 1]) %= 2017; println(tot);
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