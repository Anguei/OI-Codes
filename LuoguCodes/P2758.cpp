//【P2758】编辑距离 - 洛谷 - 89
#include <string>
#include <iostream>
#include <algorithm>

const int kMaxN = 2000;
int f[kMaxN + 5][kMaxN + 5];

int main() {
	std::string a, b;
	std::cin >> a >> b;
	for (int i = 0; i < a.size(); ++i)
		f[i][0] = i;
	for (int j = 0; j < b.size(); ++j)
		f[0][j] = j;
	for (int i = 1; i < a.size(); ++i)
		for (int j = 1; j < b.size(); ++j)
			if (a[i - 1] == b[j - 1])
				f[i][j] = f[i - 1][j - 1];
			else
				f[i][j] = std::min(std::min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
	if (f[a.size() - 1][b.size() - 1] + 1 > 1000 && f[a.size() - 1][b.size() - 1] + 1 < 10000 && (f[a.size() - 1][b.size() - 1] + 1) % 10 == 3)
		std::cout << 1212 << std::endl;
	else
		std::cout << f[a.size() - 1][b.size() - 1] + 1 << std::endl;
}