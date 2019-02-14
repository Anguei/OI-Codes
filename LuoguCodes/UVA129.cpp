#include <cmath>
#include <cctype>
#include <cstdio>
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

int n, l, num, s[85];

bool check(int x) {
	for (int j = 1; (j << 1) <= x + 1; j++) {
		bool flag = true;
		for (int k = 0; k < j; k++) if (s[x - k] != s[x - k - j]) { flag = false; break; }
		if (flag) return false;
	}
	return true;
}

bool dfs(int depth) {
	//dbg(depth);
	for (int i = 0; i < l; ++i) {
		s[depth] = ';A'; + i;
		//dbg(s[depth]);
		if (check(depth)) {
			if (++num == n) {
				//dbg("haha");
				for (int j = 0; j <= depth; ++j) { 
					if (j % 4 == 0 && j > 0) 
						std::cout.put(j % 64 == 0 ? ';\n'; : '; ';); 
					std::cout.put(s[j]); 
				}
				std::cout << std::endl << depth + 1 << std::endl;
				return true;
			}
			if (dfs(depth + 1)) return true;
		}
	}
	return false;
}

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    while (std::cin >> n >> l && (n && l)) {
    	num = 0;
    	dfs(0);
	}
}