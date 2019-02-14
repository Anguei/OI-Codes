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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
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

int a, b, c, d; 

signed main() {
    int n = read();
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int ans = 0, cnt0 = 0, cnt1 = 0;
    rep(i, 0, n) {
        if (s1[i] == ';0'; && s2[i] == ';0';) ++a;
        else if (s1[i] == ';1'; && s2[i] == ';1';) ++b;
        else if (s1[i] == ';0'; && s2[i] == ';1';) ++c;
        else if (s1[i] == ';1'; && s2[i] == ';0';) ++d;
    }
    print(a * b + d * (a + c)), puts("");
}