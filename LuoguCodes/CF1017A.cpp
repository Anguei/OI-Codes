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
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
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

const int N = 1000 + 5;
int a[N], b[N], c[N], d[N];
struct Stu {
    int a, b, c, d, id, s;
} stu[N];

signed main() {
    int n = read();
    rep(i, 1, n) stu[i].a = read(), stu[i].b = read(), stu[i].c = read(), stu[i].d = read();
    rep(i, 1, n) stu[i].s = stu[i].a + stu[i].b + stu[i].c + stu[i].d, stu[i].id = i;
    std::sort(stu + 1, stu + n + 1, [](const Stu &s1, const Stu &s2) {
        if (s1.s != s2.s) return s1.s > s2.s;
        return s1.id < s2.id;
    });
    //rep(i, 1, n) dbg(stu[i].s);
    rep(i, 1, n) if (stu[i].id == 1) return print(i), puts(""), 0;
}