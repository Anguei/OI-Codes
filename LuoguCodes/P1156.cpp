//【P1156】垃圾陷阱 - 洛谷 - Uk 
#include <cstring>
#include <iostream>
#include <algorithm>

struct Rubbish
{
	int t, f, h;
	Rubbish (int _t, int _f, int _h) : t(_t), f(_f), h(_h) {}
	Rubbish() = default;
} r[105];

int dp[105][105]; // 前 i 个垃圾到达高度 j 所维持的最长时间  

int main()
{
	int d, g;
	std::cin >> d >> g;
	for (int i = 1; i <= g; ++i)
	{
		int t, f, h;
		std::cin >> t >> f >> h;
		r[i] = Rubbish(t, f, h);
	}
	std::sort(r + 1, r + g + 1, [](const Rubbish &r1, const Rubbish &r2)
	{
		return r1.t < r2.t;
	});
	
	memset(dp, -1, sizeof dp); // 必须是负的，因为生命为 0 时依然可以进行最后一次操作 
	dp[0][0] = 10;
	for (int i = 0; i < g; ++i)
		for (int j = 0; j < d; ++j)
			if (j + r[i + 1].h >= d && dp[i][j] >= r[i + 1].t - r[i].t) // 能撑到下一次并跳出去 
			{
				std::cout << r[i + 1].t << std::endl;
				return 0;
			}
			else if (dp[i][j] - (r[i + 1].t - r[i].t) >= 0) // 能撑到下一个垃圾
			{
				dp[i + 1][j + r[i + 1].h] = std::max(dp[i + 1][j + r[i + 1].h], dp[i][j] - (r[i + 1].t - r[i].t)); // 要堆起来 
				dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + r[i + 1].f - (r[i + 1].t - r[i].t)); // 要吃掉 
			}
	
	// 跳不出去了，GG
	int rest = 10, tot = 0;
	for (int i = 1; i <= g; ++i) 
	{
		int dis = r[i].t - r[i - 1].t;
		if (dis > rest)
		{
			std::cout << rest + tot << std::endl;
			return 0;
		}
		tot += dis;
		rest -= dis;
		rest += r[i].f;
	} 
	std::cout << rest + tot << std::endl;
}