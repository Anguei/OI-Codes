//【P1118】[USACO06FEB] 数字三角形 Backward Digit Su… - 洛谷 - 60
//#pragma GCC optimize(10)
//#pragma G++ optimize(10)

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

const int kMaxN = 12;
int triangle[kMaxN + 1][kMaxN + 1], times[kMaxN + 1];

int main() {
	int n, sum;
	std::cin >> n >> sum;
	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
		v[i] = i;
	
	for (int i = 1; i < n; ++i)
		triangle[i][0] = triangle[0][i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
	triangle[0][0] = 1;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= i; ++j)
//			std::clog << triangle[i][j] << " ";
//		std::clog << std::endl;
//	}
//	std::clog << std::endl;
	
	do {
//		for (int i = 1; i < v.size(); ++i)
//			std::clog << v[i] << " ";
		
		int tSum = 0;
		for (int i = 1; i < v.size(); ++i) {
			tSum += v[i] * triangle[n - 1][i - 1];
			if (tSum > sum)
				std::sort(v.begin() + i, v.end(), std::greater<int>());
		}
//		std::clog << tSum << std::endl;
		
		if (tSum == sum) {
//			std::clog << std::endl;
			for (int i = 1; i < v.size(); ++i)
				std::cout << v[i] << " ";
			std::cout << std::endl;
			return 0;
		}
	} while (std::next_permutation(v.begin() + 1, v.end()));
}