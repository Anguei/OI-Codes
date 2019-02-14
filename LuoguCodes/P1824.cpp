#include <vector>
#include <iostream>
#include <algorithm>

bool check(int dis, int m, const std::vector<int> &a)
{
	int cnt = 1, pos = 0;
	for (int i = 1; i < a.size(); ++i)
		if (a[i] - a[pos] >= dis)
		{
			pos = i;
			if (++cnt >= m)
				return true;
		}
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	int l = a.front(), r = a.back();
	while (l < r)	
	{
		int mid = (l + r) >> 1;
		if (check(mid, m, a))
			l = mid + 1;
		else
			r = mid;
	}
	std::cout << r - 1 << std::endl;
}