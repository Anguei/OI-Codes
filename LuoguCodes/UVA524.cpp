#include <cmath>
#include <cctype>
#include <cstring>
#include <set>
#include <map>
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

int n;
int a[20]; 
bool isp[40], vis[20];

bool is_prime(int x) {
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
	return true;
}

void dfs(int depth) {
	if (depth == n + 1 && isp[a[1] + a[n]]) { rep(i, 1, n - 1) std::cout << a[i] << " "; std::cout << a[n]; std::cout << std::endl; return; }
	rep(i, 2, n) {
		if (!vis[i] && isp[i + a[depth - 1]]) {
			a[depth] = i;
			vis[i] = true;
			dfs(depth + 1);
			vis[i] = false;
		}
	}
}

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int nowT = 0;
    rep(i, 0, 39) isp[i] = is_prime(i);
    while (std::cin >> n) {
    	if (nowT) std::cout << std::endl;
    	memset(vis, false, sizeof vis);
    	std::cout << "Case " << ++nowT << ":\n";
    	a[1] = 1;
    	dfs(2);
	}
}