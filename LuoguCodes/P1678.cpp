#include <vector>
#include <iostream>
#include <algorithm>

int find1(int x, std::vector<int> &school) // 找最小的大于等于 x 的值 
{
	int l = 0, r = school.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (school[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return std::min(abs(school[l] - x), abs(school[l - 1] - x));
}

int find2(int x, std::vector<int> &school) // 找最大的小于 x 的值 
{
	int l = 0, r = school.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (school[mid] < x)
			l = mid + 1;
		else
			r = mid;
	}
	return school[l];
}

int main()
{
	int m, n;
	std::cin >> m >> n;
	std::vector<int> school(m), stu(n);
	for (int i = 0; i < m; ++i)
		std::cin >> school[i];
	for (int i = 0; i < n; ++i)
		std::cin >> stu[i];
	std::sort(school.begin(), school.end());
	int ans = 0;
	for (auto it : stu)
	{
		/*int tmp1 = find1(it, school);
		int tmp2 = find2(it, school);
		tmp1 = abs(tmp1 - it);
		tmp2 = abs(tmp2 - it);
		std::clog << tmp1 << " " << tmp2 << std::endl;*/
		ans += (it <= school.front() ? school.front() - it : find1(it, school));
		//std::clog << tmp1 << std::endl; 
		/*auto p1 = std::lower_bound(school.begin(), school.end(), it);
		auto p2 = std::lower_bound(school.begin(), school.end(), it, std::greater<int>());
		int tmp1 = (p1 != school.end() ? *p1 : 0x7fffffff);
		int tmp2 = (p2 != school.end() ? *p2 : 0x7fffffff);
		tmp1 = abs(tmp1 - it);
		tmp2 = abs(tmp2 - it);
		int tmp = std::min(tmp1, tmp2);
#ifndef ONLINE_JUDGE
		std::clog << tmp1 << " " << tmp2 << " " << tmp << std::endl;
#endif
		ans += tmp; */
	}
	std::cout << ans << std::endl;
}
