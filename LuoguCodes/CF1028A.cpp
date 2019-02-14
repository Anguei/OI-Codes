#include <iostream>
#include <algorithm> 

char map[120][120];

int main() {
	int n, m, x1 = 999, x2 = 0, y1 = 999, y2 = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			std::cin >> map[i][j];
			if (map[i][j] == ';B';) {
				x1 = std::min(i, x1);
				y1 = std::min(j, y1);
				x2 = std::max(i, x2);
				y2 = std::max(j, y2);
			}
		}
	}
	if (x2 == 0) {
		std::cout << x1 << " " << y1 << std::endl;
	} else {
		std::cout << (x1 + x2) / 2 << " " << (y1 + y2) / 2 << std::endl;
	}
}