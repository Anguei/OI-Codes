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

const int N = 100000 + 5, p = 1000000007;
int n, m, a[N], bit1[N], bit2[N], inv[N];

#define lowbit(x) ((x) & (-x))
void add1(int pos, int val) { while (pos <= n) (bit1[pos] += val) %= p, pos += lowbit(pos); }
void add2(int pos, int val) { while (pos <= n) (bit2[pos] += val) %= p, pos += lowbit(pos); }
int query1(int pos) { int res = 0; while (pos > 0) (res += bit1[pos]) %= p, pos -= lowbit(pos); return res; }
int query2(int pos) { int res = 0; while (pos > 0) (res += bit2[pos]) %= p, pos -= lowbit(pos); return res; }

void solution() {
    n = read(), m = read(); 
    inv[1] = 1; rep(i, 2, n) inv[i] = (p - p / i) * inv[p % i] % p;
    rep(i, 1, n) a[i] = read(), add1(i, a[i]), add2(i, a[i] * a[i] % p); while (m--) {
        int opt = read(), l = read(), r = read();
        if (opt == 1) {
            int old1 = (query1(l) - query1(l - 1) + p) % p; add1(l, (r - old1 + p) % p);
            int old2 = (query2(l) - query2(l - 1) + p) % p; add2(l, (r * r % p - old2 + p) % p);
        } else if (opt == 2) {
            // 先把不带逆元的情况算出来，最后加上逆元计算。
            int normalAver = ((query1(r) - query1(l - 1) + p) % p) * inv[(r - l + 1)] % p;
            int sqrAver = ((query2(r) - query2(l - 1) + p) % p) * inv[(r - l + 1)] % p;
            println((sqrAver - (normalAver * normalAver % p) + p) % p); // 区间平方平均值减去区间平均值的平方
        }
    }
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