//【CF1005A】Tanya and Stairways - 洛谷 - Ac 
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), ans;
	int ans1 = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		if (a[i] == 1)
		{
			++ans1;
			if (i != 1)
				ans.push_back(a[i - 1]);
		}
		
	} 
	std::cout << ans1 << std::endl;
	for (auto i : ans)
		std::cout << i << " ";
	std::cout << a.back() << std::endl;
}