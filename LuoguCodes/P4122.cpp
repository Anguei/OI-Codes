//【P4122】[USACO17DEC]Blocked Billboard - 洛谷 - 70
#include <cmath>

#include <iostream>
#include <algorithm>

struct Square {
	int x1, y1, x2, y2;
} s[3];

int area(Square x) {
	return std::abs(x.x1 - x.x2) * std::abs(x.y1 - x.y2);
}

int calc(Square a, Square b) {
	return std::max(0, std::min(a.x2, b.x2) - std::max(a.x1, b.x1)) * std::max(0, std::min(a.y2, b.y2) - std::max(a.y1, b.y1));
}

int main() {
	for(int i = 0; i < 3; ++i)
        std::cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
	std::cout << area(s[0]) + area(s[1]) - calc(s[0], s[2]) - calc(s[1], s[2]) << std::endl;
}

