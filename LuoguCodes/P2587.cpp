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

const int N = 100000 + 5;
int n, a[N], b[N];

int query1() {
    int l1 = n, l2 = n, r1 = 1, r2 = 1, ans = 0;
    rep(i, 1, n) {
        if (a[l1] > b[l2]) {
            ans += 2;
            --l1, --l2;
        } else if (a[r1] > b[r2]) {
            ans += 2;
            ++r1, ++r2;
        } else if (a[r1] < b[l2]) {
            ans -= 0;
            ++r1, --l2;
        } else if (a[r1] == b[l2]) {
            ans += 1;
            ++r1, --l2;
        }
    } return ans;
}

int query2() {
    int l1 = n, l2 = n, r1 = 1, r2 = 1, ans = 0;
    rep(i, 1, n) {
        if (b[l1] > a[l2]) {
            ans += 2;
            --l1, --l2;
        } else if (b[r1] > a[r2]) {
            ans += 2;
            ++r1, ++r2;
        } else if (b[r1] < a[l2]) {
            ans -= 0;
            ++r1, --l2;
        } else if (b[r1] == a[l2]) {
            ans += 1;
            ++r1, --l2;
        }
    } return ans;
}

void solution() {
    n = read(); 
    rep(i, 1, n) a[i] = read(); std::sort(a + 1, a + n + 1);
    rep(i, 1, n) b[i] = read(); std::sort(b + 1, b + n + 1);
    print(query1()), pc('; ';), println((n << 1) - query2());
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
// D1T3 P1316
// 不要颓废
// 不 要 颓 废
// 不  要  颓  废
// 不   要   颓   废
// 不    要    颓    废
// 不     要     颓     废