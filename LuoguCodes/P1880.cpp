#include <iostream>
#include <algorithm>

const int kMaxN = 100;

int a[2 * kMaxN + 5], sum[2 * kMaxN + 5];
int dp1[2 * kMaxN + 5][2 * kMaxN + 5], dp2[2 * kMaxN + 5][2 * kMaxN + 5];

int dfs1(int l, int r)
{
	if (dp1[l][r])
		return dp1[l][r];
	if (l == r)
		return dp1[l][r] = 0;
	int res = 0x7fffffff;	
	for (int i = l; i < r; ++i) 
		res = std::min(res, dfs1(l, i) + dfs1(i + 1, r) + sum[r] - sum[l - 1]);	
	return dp1[l][r] = res;
}

int dfs2(int l, int r)
{
	if (dp2[l][r])
		return dp2[l][r];
	if (l == r)
		return dp2[l][r] = 0;
	int res = 0;
	for (int i = l; i < r; ++i)
		res = std::max(res, dfs2(l, i) + dfs2(i + 1, r) + sum[r] - sum[l - 1]);
	return dp2[l][r] = res;
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{	
		std::cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; ++i)
		sum[i] = sum[i - 1] + a[i];
		
	dfs1(1, 2 * n);
	dfs2(1, 2 * n);
	
	int min = 0x7fffffff, max = 0;
	for (int i = 1; i <= n; ++i)
	{
		min = std::min(min, dp1[i][n + i - 1]);
		max = std::max(max, dp2[i][n + i - 1]);
	}
	std::cout << min << std::endl << max << std::endl;
}