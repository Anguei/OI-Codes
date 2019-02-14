//【P2822】组合数问题 - 洛谷 - 100
#include <iostream> 

const int kMaxN = 2000, kMaxM = 2000;
int c	[kMaxN + 5][kMaxM + 5];
int sum	[kMaxN + 5][kMaxM + 5];

inline void init(int k) {
	for (register int i = 0; i <= 2000; ++i)
		c[i][i] = c[i][0] = 1;
	for (register int i = 1; i <= 2000; ++i)
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
	for (register int i = 1; i <= 2000; ++i) 
		for (register int j = 1; j <= 2000; ++j) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
			if (!c[i][j] && j <= i)
				++sum[i][j];
		}
#ifndef ONLINE_JUDGE
	for (int i = 1; i <= 7; ++i) {
		for (int j = 1; j <= 7; ++j)
			std::cout << sum[i][j] << " ";
		std::cout << std::endl;
	}
#endif
}

int main() {
    std::ios::sync_with_stdio(false);
	register int T, k;
	std::cin >> T >> k;
	init(k);
	while (T--) {
		register int n, m;
		std::cin >> n >> m;
		std::cout << sum[n][m] << std::endl;
	}
}