#include <cmath>
#include <utility>
#include <iomanip>
#include <iostream>
#include <algorithm>

const int N = 5000 + 5;

int x[N], y[N];
bool vis[N];
double dis[N];

double getDis(int a, int b)
{
	double dx = x[a] - x[b], dy = y[a] - y[b];
	return sqrt(dx * dx + dy * dy);
}

int main() {
	// Prim 算法 
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> x[i] >> y[i],
		dis[i] = 1e9;
	dis[1] = 0;
	double ans = 0.0;
	for (int i = 1; i <= n; ++i) {
		int pos = 0;
		double tot = 1e9;
		for (int j = 1; j <= n; ++j) // 找最近的 
			if (!vis[j] && dis[j] < tot)
				pos = j, tot = dis[j];
		ans += tot; // 加上 
		vis[pos] = true; // 标记 
		for (int j = 1; j <= n; ++j) // 更新距离 
			dis[j] = std::min(dis[j], getDis(j, pos));
	}
	std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
}