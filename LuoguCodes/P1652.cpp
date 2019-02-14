//【P1652】圆 - 洛谷 - 20
#include <cmath>
#include <iostream>

int main() {
	int n, ans = 0;
	std::cin >> n;
	int *x = new int[n + 1], *y = new int[n + 1], *r = new int[n + 1];
	for (int i = 1; i <= n; ++i) std::cin >> x[i]; for (int i = 1; i <= n; ++i) std::cin >> y[i]; for (int i = 1; i <= n; ++i) std::cin >> r[i];
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 1; i <= n; ++i) if ((sqrt((x1 - x[i]) * (x1 - x[i]) + (y1 - y[i]) * (y1 - y[i])) < r[i] && sqrt((x2 - x[i]) * (x2 - x[i]) + (y2 - y[i]) * (y2 - y[i])) > r[i]) || (sqrt((x2 - x[i]) * (x2 - x[i]) + (y2 - y[i]) * (y2 - y[i])) < r[i] && sqrt((x1 - x[i]) * (x1 - x[i]) + (y1 - y[i]) * (y1 - y[i])) > r[i])) ++ans;
	std::cout << ans << std::endl; 
}