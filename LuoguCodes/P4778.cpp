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

const int N = 100000 + 5, mod = 1000000009;
int n, a[N], fact[N];
bool v[N];

int qpow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

void solution() {
    n = read(); rep(i, 1, n) a[i] = read();
    memset(v, false, sizeof v);
    int ans = 1, cnt = 0;
    rep(i, 1, n) if (!v[i]) {
        int len = v[i] = 1;
        for (int j = a[i]; j != i; j = a[j]) len += (v[j] = true);
        ++cnt;
        ans = ans * (len == 1 ? 1 : qpow(len, len - 2, mod)) % mod;
        ans = ans * qpow(fact[len - 1], mod - 2, mod) % mod;
    }
    print(ans * fact[n - cnt] % mod), puts("");
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
    fact[0] = 1; rep(i, 1, 100000) fact[i] = fact[i - 1] * i % mod;
    int T = read(); while (T--) solution();
}