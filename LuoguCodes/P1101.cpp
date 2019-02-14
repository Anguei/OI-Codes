//【P1101】单词方阵 - 洛谷 - 0 
#include <string>
#include <iostream>

const int MAXN = 100;

int n;
std::string map[MAXN + 5];
std::string word = "yizhong";
bool vis[MAXN + 5][MAXN + 5];
const int dir[8][2] = { { -1,0 },{ -1,-1 },{ -1,1 },{ 0,1 },{ 0,-1 },{ 1,0 },{ 1,-1 },{ 1,1 } };

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::string t;
		std::cin >> t;
		map[i] = " " + t;//下标从一开始
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!vis[i][j]) {
				for (int k = 0; k < 8; ++k) {
					int dx = i + dir[k][0] * 6, dy = j + dir[k][1] * 6;
					if (dx >= 1 && dy >= 1 && dx <= n && dy <= n) {
						bool t = true;
						for (int l = 0; l < 7; ++l) {
							int dx2 = i + dir[k][0] * l, dy2 = j + dir[k][1] * l;
							if (vis[dx2][dy2] || word[l] != map[dx2][dy2])
								t = false;
						}
						if (t) {
							for (int l = 0; l < 7;  ++l) {
								int dx2 = i + dir[k][0] * l, dy2 = j + dir[k][1] * l;
								vis[dx2][dy2] = true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (vis[i][j])
				std::cout.put(map[i][j]);
			else
				std::cout.put(';*';);
		}
		std::cout << std::endl;
	}
	return 0;
}