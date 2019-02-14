//【CF978E】Bus Video System - 洛谷 - Ac
#include <iostream>

#define debug(x) std::cout << #x << " = " << x << std::endl

const int kMaxN = 1000;

int a[kMaxN + 5], sum[kMaxN + 5];

int main()
{
	int n, w;
	std::cin >> n >> w;
	int minSum = 0x7fffffff, maxSum = -0x80000000; 
	for (int i = 1; i <= n; ++i) 
	{
		std::cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		minSum = std::min(minSum, sum[i]);
		maxSum = std::max(maxSum, sum[i]);
	}
	
	int max = (maxSum < 0 ? w : w - maxSum);
	int min = (minSum < 0 ? -minSum : 0);
	
	//debug(max), debug(min);
	std::cout << (max - min + 1 < 0 ? 0 : max - min + 1) << std::endl;
}
 