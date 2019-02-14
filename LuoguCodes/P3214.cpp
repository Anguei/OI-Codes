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
#define fn "2339"
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

// dp[i] = A(2^n-1, i-1) − dp[i−1] − (dp[i−2] ∗ (i−1) ∗ (2^n-1-(i-2)))
// dp[0] = 1, dp[1] = 0

const int N = 1000000 + 5, p = 100000007;
int n, m, powed, dp[N], fact[N], invFact[N], inv[N], A[N];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= p;
        (a *= a) %= p; b >>= 1;
    } return res % p;
}

void solution() {
    n = read(), m = read(); powed = qpow(2, n) - 1;
    rep(i, 1, m) A[i] = A[i - 1] * (powed - i + 1) % p;
    dp[0] = fact[0] = invFact[0] = inv[1] = A[0] = 1;
    rep(i, 2, std::max(n, m)) inv[i] = (p - p / i) * inv[p % i] % p;
    rep(i, 1, std::max(n, m)) fact[i] = fact[i - 1] * i % p, invFact[i] = invFact[i - 1] * inv[i] % p;
    rep(i, 1, std::max(n, m)) A[i] = A[i - 1] * (powed - i + 1) % p;
    // rep(i, 2, m) dp[i] = ((A(qpow(2, n) - 1, i - 1) - dp[i - 1] + p) % p - (dp[i - 2] * (i - 1) + p) % p * (qpow(2, n) - 1 - (i - 2)) % p); println(dp[m]);
    // rep(i, 2, m) dp[i] = ((A(qpow(2, n) - 1, i - 1) - dp[i - 1] + p) % p - (dp[i - 2] * (i - 1) % p * (qpow(2, n) - 1 - (i - 2))) % p + p) % p; println(dp[m]);
    // rep(i, 2, m) { dp[i] = A(qpow(2, n) - 1, i - 1) - dp[i - 1] + p; dp[i] -= dp[i - 2] * (i - 1) % p * (qpow(2, n) - 1 - (i - 2)) % p; dp[i] = (dp[i] % p + p) % p; } println(dp[m]);
    // rep(i, 2, m) dp[i] = ((A(powed, i - 1) - dp[i - 1] + p) % p - (dp[i - 2] * (i - 1) % p * (powed - 1 - (i - 2))) % p + p) % p; println(dp[m]);
    rep(i, 2, m) dp[i] = ((A[i - 1] - dp[i - 1] + p) - (dp[i - 2] * (i - 1) % p * (powed - (i - 2)) % p) % p + p) % p; println(dp[m] * invFact[m] % p);
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