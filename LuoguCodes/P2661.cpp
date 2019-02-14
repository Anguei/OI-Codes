#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#ifdef yyfLocal
#define dbg(x) std::clog << #x << " = " << x << std::endl
#else
#define dbg(x) x
#endif

const int N = 200000 + 5;

int ans = 0x3f3f3f3f;
int dis[N], fa[N];
//bool vis[N];
//std::vector<int> g[N];

int find(int x) {
	if (x == fa[x]) return x;
	int last = fa[x];
	fa[x] = find(fa[x]);
	dis[x] += dis[last];
	return fa[x];
}

void merge(int a, int b) {
	int pa = find(a); int pb = find(b);
	if (pa ^ pb) {
		fa[pa] = pb;
		dis[a] = dis[b] + 1;
	} else {
		ans = std::min(ans, dis[a] + dis[b] + 1);
	}
}

int main() {
#ifdef yyfLocal
	freopen("testdata.in", "r", stdin); 
#endif
	std::ios::sync_with_stdio(false); std::clog.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i) {
		int t;
		std::cin >> t;
		merge(i, t);
	}
	std::cout << ans << std::endl; 
}