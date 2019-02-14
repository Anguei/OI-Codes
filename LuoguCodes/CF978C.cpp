//【CF978C】Letters - 洛谷 - Ac 
#include <iostream>
#include <algorithm>

const int kMaxNM = 200000;

long long a[kMaxNM + 5], B[kMaxNM + 5], sum[kMaxNM + 5];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i]; 
		sum[i] = sum[i - 1] + a[i];
	}
		
	for (int i = 1; i <= m; ++i)
	{
		long long b;
		std::cin >> b;
		long long pos = std::lower_bound(sum + 1, sum + n + 1, b) - sum;
		std::cout << pos << " " << b - sum[pos - 1]  << std::endl;
	}
	
}