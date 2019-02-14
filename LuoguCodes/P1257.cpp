//【P1257】平面上的最接近点对 - 洛谷 - 0 
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

const unsigned kMaxN = 10000;

struct Point {
	double x, y;
	Point(double _x, double _y) : x(_x), y(_y) {}
	Point() {}
} points[kMaxN + 5];

int main() {
	double ans = 0x7fffffff;
	register unsigned n;
	std::cin >> n;
	for (register unsigned i = 1; i <= n; ++i) {
		register double x, y;
		std::cin >> x >> y;
		points[i] = Point(x, y);
	}
	for (register unsigned i = 1; i <= n; ++i) {
		for (register unsigned j = i - 1; j >= 1; --j) {
			auto lambda = [](const Point &p1, const Point &p2) { double x = fabs(p1.x - p2.x), y = fabs(p1.y - p2.y); return sqrt(x * x + y * y); };
			ans = std::min(ans, lambda(points[i], points[j]));
		}
	}
	printf("%.4f\n", ans);
}