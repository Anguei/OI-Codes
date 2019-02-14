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

const int N = 1005;

signed main()
{
    int n = read();
    int a[N] = {0};
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n)
    {
        bool vis[N] = {0};
        int j;
        for (j = i; !vis[j]; j = a[j])
            vis[j] = true;
        print(j), pc('; ';);
    }
    puts("");
}