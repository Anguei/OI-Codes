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

struct Data {
    int x, y;
    Data() {}
    Data(int x, int y) : x(x), y(y) {}
    bool operator < (const Data &rhs) const { return x < rhs.x; }
};

const int N = 100000 + 5;
int n, ans, last, cnt[N], s[N], b[N]; Data a[N];
//int n, a[N], b[N];

void solution() {
    /*std::set<int> set;
    n = read(); rep(i, 1, n) a[i] = read(), set.insert(a[i]), b[i] = set.size();
    if (set.size() >= n) { puts("Impossible"); return; }
    puts("Possible"); rep(i, 1, n) print(b[i]), pc('; ';);*/
    n = read(); rep(i, 1, n) s[i] = read(), a[i] = Data(n - s[i], i);
    std::sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        if (a[i].x != a[i - 1].x || i - last >= a[i].x) ++ans, last = i;
        b[a[i].y] = ans;
    }
    rep(i, 1, n) ++cnt[b[i]];
    rep(i, 1, n) if (n - cnt[b[i]] != s[i]) { puts("Impossible"); return; }
    puts("Possible"); rep(i, 1, n) print(b[i]), pc('; ';);
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