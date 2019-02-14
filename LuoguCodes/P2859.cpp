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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
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
    int time, index;
    bool flag;
    Data () {}
    Data (int time, int index, bool flag) : time(time), index(index), flag(flag) {}
    bool operator < (const Data &rhs) const {
        if (time != rhs.time) return time < rhs.time;
        else if (index != rhs.index || flag != rhs.flag) return flag;
        else return index < rhs.index;
    }
};

const int N = 100000 + 5;
int n, tot = 1, cur, ans[N], able[N];
Data a[N << 1];

void solution() {
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
    n = read();
    rep(i, 0, n) {
        a[lson(i)].time = read(); a[rson(i)].time = read();
        a[lson(i)].index = a[rson(i)].index = i;
		a[lson(i)].flag = true; a[rson(i)].flag = false;
    }
    std::sort(a, a + n + n);
    rep(i, 0, (n << 1)) {
        if (!a[i].flag) able[cur++] = ans[a[i].index];
        else ans[a[i].index] = (cur == 0) ? ++tot : able[--cur];
    }
    print(tot - 1), pc(';\n';);
    rep(i, 0, n) print(ans[i] - 1), pc(';\n';);
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