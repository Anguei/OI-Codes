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
#define fn "testdata"
#define ll long long
// #define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

const int N = 3e5 + 5;
int n, m, a[N]; ll pre[520][520];

void solution() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int j=1;j<=n;j++) for(int i=1;i<=500;i++) pre[i][j%i]+=a[j];
	while (m--) {
		char opt = 0; std::cin >> opt; int x, y; scanf("%d %d", &x, &y);
		if (opt == ';A';) {
			if (x <= 500) printf("%lld\n", pre[x][y]);
			else { ll ans = 0; for (int j = y; j <= n; j += x) ans += a[j]; printf("%lld\n", ans); }
		} else if (opt == ';C';) {
			int old = a[x]; a[x] = y;
			for (int j = 1; j <= 500; ++j) pre[j][x % j] += (ll)y - old;
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
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}
