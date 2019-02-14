// luogu-judger-enable-o2
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 50000 + 5;

int max[N][17], min[N][17];

void init(int n)
{
	for (int j = 1; (1 << j) <= n; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
			min[i][j] = std::min(min[i][j - 1], min[i + (1 << (j - 1))][j - 1]);
		}
}

int rmq(int l, int r)
{
	int k = log(r - l + 1) / log(2);
	int upper = std::max(max[l][k], max[r - (1 << k) + 1][k]);
	int lower = std::min(min[l][k], min[r - (1 << k) + 1][k]);
	//std::clog << upper << " " << lower << std::endl;
	return upper - lower;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("testdata.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, q;
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> max[i][0],
		min[i][0] = max[i][0];
	}
		
	init(n);
		
	while (q--)
	{
		int l, r;
		std::cin >> l >> r;
		std::cout << rmq(l, r) << std::endl;
	}
}