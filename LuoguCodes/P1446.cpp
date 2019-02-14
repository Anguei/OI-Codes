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
#define fn "1004"
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

const int N = 60 + 5;
int a, b, c, d, p, fact[N], invFact[N], inv[N];

int C(int n, int m) {
    // C(n, m) = n! / m! / (n - m)!
    return fact[n] * invFact[m] % p * invFact[n - m] % p;
}

// ( a + b + c)! / (a! ∗ b! ∗ c! ∗ (d + 1))
void solution() {
    a = read(), b = read(), c = read(), d = read(), p = read();
    fact[0] = invFact[0] = inv[1] = 1;
    rep(i, 1, std::max(a + b + c, d)) fact[i] = fact[i - 1] * i % p;
    rep(i, 2, std::max(a + b + c, d)) inv[i] = (p - p / i) * inv[p % i] % p;
    rep(i, 1, std::max(a + b + c, d)) invFact[i] = invFact[i - 1] * inv[i] % p;
    println(fact[a + b + c] * invFact[a] % p * invFact[b] % p * invFact[c] % p * inv[d + 1] % p);
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