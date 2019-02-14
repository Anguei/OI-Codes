//【P1509】找啊找啊找 GF - 洛谷 - 100 
#include <iostream>
#include <algorithm>

int n, m, r;
const int kMaxN = 100, kMaxM = 100, kMaxR = 100; // 常量开头带 k，符合命名规范 
int rmb[kMaxN + 5], rp[kMaxN + 5], time[kMaxN + 5];
int dpNum[kMaxM + 5][kMaxR + 5], dpTime[kMaxM + 5][kMaxR + 5]; // 两个 dp 

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> rmb[i] >> rp[i] >> time[i];
	std::cin >> m >> r;

	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= rmb[i]; --j) // 小心，不要把 j 和 m 写混，否则死循环 
			for (int k = r; k >= rp[i]; --k) {
				// 如果能泡到更多妹子 
				if (dpNum[j][k] < dpNum[j - rmb[i]][k - rp[i]] + 1) {
					dpNum[j][k] = dpNum[j - rmb[i]][k - rp[i]] + 1;
					dpTime[j][k] = dpTime[j - rmb[i]][k - rp[i]] + time[i];
				}
				else if (dpNum[j][k] == dpNum[j - rmb[i]][k - rp[i]] + 1)
					// 如果能泡到同样多的妹子，选择时间最少的方案 
					dpTime[j][k] = std::min(dpTime[j][k], dpTime[j - rmb[i]][k - rp[i]] + time[i]);
			}
	
	// 不需要特判能否泡到妹子，因为如果泡不到，这里的值一定为 0 
	std::cout << dpTime[m][r] << std::endl;
}