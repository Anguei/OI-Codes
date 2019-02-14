#include <vector> 
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::sort(a.begin() + 1, a.end());	
	std::vector<int> b(a);
	int la, lb, ra, rb, ans = 0;
	for (la = lb = 1, ra = rb = n; la <= ra && lb <= rb; )
	{
		if (a[ra] < b[lb])
		{
			--ra;
			++lb;
			++ans;
		} 
		else if (a[ra] < b[rb])
		{
			--ra;
			--rb;
			++ans;
		}
		else
		{
			--ra;
			++lb;
		}
	}
	std::cout << ans << std::endl;
}