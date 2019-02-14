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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

int n, ans = 0, a[30];
std::map<int, int> map;

void solution() {
    std::cin >> n;
    while (n--) {
        std::string s; std::cin >> s;
        memset(a, 0, sizeof a);
        rep(i, 0, s.size() - 1) a[s[i] - 97] ^= 1;
        int sum = 0;
        rep(i, 0, 25) sum |= a[i] << i;
        ans += map[sum]; ++map[sum];
        rep(i, 0, 25) ans += map[sum ^ 1 << i];
    }
    std::cout << ans << std::endl;
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