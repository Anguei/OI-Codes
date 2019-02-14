//【P1506】拯救 oibh 总部 - 洛谷 - 0 
#include <iostream> 

const int kMaxX = 500, kMaxY = 500;
int map[kMaxX + 5][kMaxY + 5] = { 0 };
const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int x, y;

void dfs(int m, int n) {
	// 为啥下面的判断越界改掉之后就对了。。。 
	//if (m < 1 || n < 1 || m > x || n > y)
	if (m < 0 || n < 0 || m > x + 1 || n > y + 1)
		return;
	if (map[m][n])// 如果是墙，或者已经被挡住 
		return;
	map[m][n] = 2;
	for (int i = 0; i < 4; ++i) 
		dfs(m + dir[i][0], n + dir[i][1]);
}

void displayMap() {
	std::cout << std::endl;
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j)
			std::cout << map[i][j];
		std::cout << std::endl;
	}
}

int main() {
	std::cin >> x >> y;
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j) {
			char ch;
			std::cin >> ch;
			// 如果是墙(';*';) ，为 true 
			map[i][j] = (ch == ';*'; ? 1 : 0);
		}
	//displayMap();
	//[] () { std::cout << std::endl; for (int i = 1; i <= x; ++i) { for (int j = 1; j <= y; ++j) std::cout << map[i][j]; std::cout << std::endl; } };
	dfs(0, 0);
	//[] () { std::cout << std::endl; for (int i = 1; i <= x; ++i) { for (int j = 1; j <= y; ++j) std::cout << map[i][j]; std::cout << std::endl; } };
	//displayMap();
	int ans = 0;
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j)
			if (map[i][j] == 0)
				++ans;
	}
	std::cout << ans << std::endl;
}