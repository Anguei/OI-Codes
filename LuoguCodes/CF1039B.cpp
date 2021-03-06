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
#define pc(x) std::cout.put(x)
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
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

int n, k, l, r;

bool ask(int l, int r) {
    std::cout << l << " " << r << std::endl;
    std::string s; std::cin >> s;
    return s == "Yes";
}

void solution() {
    srand(19260817);
    n = read(), k = read(), l = 1, r = n;
    while (true) {
        int len = r - l + 1;
        int tmp = ((len + 1) >> 1) - k;
        if (tmp <= 2) {
            int x = rand() % (len + k + k);
            if (ask(std::max(1ll, std::min(n, l - k + x)), std::max(1ll, std::min(n, l - k + x)))) return;
            else l = std::max(1ll, l - k), r = std::min(n, r + k);
        } else {
            if (ask(std::max(1ll, l - k), std::max(1ll, r - k - tmp))) l = std::max(1ll, l - k), r = std::max(1ll, r - k - tmp);
            else l = std::min(n, std::max(1ll, r - k - tmp)), r = std::min(n, r + k);
        }
    }
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
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}
// Fark UKE