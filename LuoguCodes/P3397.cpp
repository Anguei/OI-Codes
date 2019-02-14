//【P3397】地毯 - 洛谷 - 0 
#include <iostream>
#include <algorithm>

const int kMaxN = 1000, kMaxM = 1000;
int a[kMaxN + 5][kMaxN + 5];

int main() {
	int n, m;
	std::cin >> n >> m;
	while (m--) {
		int x1, x2, y1, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j)
				++a[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}