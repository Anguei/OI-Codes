//【CF978D】Almost Arithmetic Progression - 洛谷 - Ac 
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

const int kMaxN = 100000;

int b[kMaxN + 5], a[kMaxN + 5];
//int x[] = {0, 0, 1, -1};

/*
int work()
{
	int res = 0;
	int dis = a[2] - a[1];
	for (int i = 3; i <= n; ++i)
	{ 
		a[i] = a[i - 1] + dis;
		if (abs(a[i] - b[i]) > 1)
			return 0;
	} 
}
*/

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> b[i];
	if (n == 1 || n == 2)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	
	/*
	int min = 0x7fffffff;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			a[1] = b[1] + x[i];
			a[2] = b[2] + x[j];
			int base = a[1] != b[1]  + a[2] != b[2];
			min = std::min(min, work() + base) ;
		}
	}
	*/
	
	
	
	int min = 0x7fffffff;
	for (int i = b[1] - 1; i <= b[1] + 1; ++i)
	{
		for (int j = b[2] - 1; j <= b[2] + 1; ++j)
		{
			int ans = (i != b[1]) + (j != b[2]);
			memset(a, 0, sizeof(a));
			int dis = j - i;
			a[1] = i, a[2] = j;
			for (int k = 3; k <= n; ++k)
				a[k] = a[k - 1] + dis;
			for (int k = 3; k <= n; ++k)
			{
				if (abs(a[k] - b[k]) == 1)
					++ans; 
				else if (abs(a[k] - b[k]) > 1) 
					goto nextFor;
			} 
			min = std::min(min, ans);
		nextFor:
			;
		}
	}
	std::cout << (min == 0x7fffffff ? -1 : min)<< std::endl;
	
}