// L';g';Version
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
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x " = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read()
{
    int res = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == ';-';)
            flag = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x)
{
    if (x < 0)
        putchar(';-';), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + 48);
}

int n, m, a, b, q;

signed main()
{
    n = read(), m = read(), a = read(), b = read(), q = read();
    while (q--)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        int ans = 0, pos = y1;
        if (x1 != x2)
        {
            if (y1 < a)
                pos = a, ans = a - y1;
            if (y1 > b)
                pos = b, ans = y1 - b;
        }
        ans += abs(x1 - x2);
        ans += abs(y2 - pos);
        print(ans), puts("");
    }
}