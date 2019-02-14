//【CF995B】Suit and Tie - 洛谷 - Ac 
#include <cstring>
#include <iostream> 
#include <algorithm>

int a[205]; // 输入 
int b[105]; // 第一次出现位置 

int main()
{
	memset(b, -1, sizeof b);
	int n;
	std::cin >> n;
	for (int i = 0; i < (n << 1); ++i)
	{
		std::cin >> a[i];
		if (b[a[i]] == -1)
			b[a[i]] = i;
	} 
	int ans = 0;
	for (int i = 0; i < (n << 1); ++i)
		for (int j = 0; j < i; ++j)
			if (b[a[i]] < b[a[j]])
				++ans;
	std::cout << ans << std::endl;
}