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
#else
#define dbg(x) 42
#define logs(x) 42
#endif
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include "immintrin.h"
#include "emmintrin.h"

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

const int N = 100000 + 10;
__m256i _s[N / 8];
int n, m, *s = reinterpret_cast<int*>(_s);

void update(int l, int r, int x) {
    // logs("updating");
    ++r;
    while ((l & 7) && l < r) s[l] > x ? s[l] -= x : 0, ++l;
    if (l == r) return;
    while (r & 7) --r, s[r] > x ? s[r] -= x : 0;
    if (l == r) return;
    l >>= 3, r >>= 3;
    __m256i *s = _s + l, t = _mm256_set_epi32(x, x, x, x, x, x, x, x);
    for (r -= l; r; --r, ++s) *s = _mm256_sub_epi32(*s, _mm256_and_si256(_mm256_cmpgt_epi32(*s, t), t));
}

#define ret { println(ans); return; }
void query(int l, int r, int x) {
    // logs("querying");
    int ans = 0; ++r;
    while ((l & 7) && l < r) ans += s[l++] == x;
    if (l == r) ret;
    while (r & 7) ans += s[--r] == x;
    if (l == r) ret;
    l >>= 3, r >>= 3;
    __m256i *s = _s + l, t = _mm256_set_epi32(x, x, x, x, x, x, x, x), res = _mm256_setzero_si256();
    for (r -= l; r; --r, ++s) res = _mm256_add_epi32(res, _mm256_cmpeq_epi32(*s, t));
    rep(i, 0, 7) ans -= (reinterpret_cast<int*>(&res))[i]; println(ans);
}

void solution() {
    n = read(), m = read();
    rep(i, 1, n) s[i] = read();
    while (m--) {
        int opt = read(), l = read(), r = read(), x = read();
        opt ^ 1 ? query(l, r, x) : update(l, r, x); 
    }
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
