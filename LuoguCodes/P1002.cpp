//【P1002】过河卒 - 洛谷 - 0 
#include <iostream>

using ll = long long;

ll map[25][25], ans[25][25];

void mark(ll x, ll y) {
	map[x][y] = 1;
    map[x - 1][y - 2] = 1;
    map[x - 2][y - 1] = 1;
    map[x - 2][y + 1] = 1;
    map[x - 1][y + 2] = 1;
    map[x + 1][y - 2] = 1;
    map[x + 2][y - 1] = 1;
    map[x + 2][y + 1] = 1;
    map[x + 1][y + 2] = 1;
}

int main() {
	ll bx, by, mx, my;
	std::cin >> bx >> by >> mx >> my;
	mark(mx, my);
	ans[1][0] = 1;
	for (int i = 1; i <= bx + 1; ++i)
		for (int j = 1; j <= by + 1; ++j) {
			//mark(i, j);
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			if (map[i - 1][j - 1])
				ans[i][j] = 0;
		}
	std::cout << ans[bx + 1][by + 1] << std::endl;
	return 0;
}