// L';g';VersionFUCKUKE
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

const int N = 100000 + 5;
int n, f[N];

int query(int x) {
    int y = (x + n / 2 - 1) % n + 1;
    if (f[x] == -1) {
        std::cout << "? " << x << std::endl;
        std::cin >> f[x];
    }
    if (f[y] == -1) {
        std::cout << "? " << y << std::endl;
        std::cin >> f[y];
    }
    return f[y] - f[x];
}

void bs(int l, int r) {
    int x = query(l), y = query(r);
    if (x == 0) { std::cout << "! " << l << std::endl; exit(0); }
    if (y == 0) { std::cout << "! " << r << std::endl; exit(0); }
    int mid = (l + r) >> 1; int z = query(mid);
    if (y == 0) { std::cout << "! " << mid << std::endl; exit(0); }
    if ((x < 0 && z > 0) || (x > 0 && z < 0)) bs(l, mid);
    else bs(mid, r);
}

signed main() {
    std::cin >> n;
    if (n % 4 == 2) return std::cout << "! -1" << std::endl, 0;
    memset(f, -1, sizeof f);
    bs(1, n / 2 + 1);
}