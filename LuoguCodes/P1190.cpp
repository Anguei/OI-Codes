//【P1190】接水问题 - 洛谷 - 0
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int getMax(int* w, int n)
{
	int maxR = 0;
	for (int i = 1; i <= n; ++i)
		maxR = max(maxR, w[i]);
	return maxR;
}

int main()
{
	int n, m, sum;
	cin >> n >> m;
	int* w = new int[n + 1];
	w[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		cin >> w[i];
		sum  += w[i];
	}

	/*if (n < m)
	{
		int maxA = 0;
		for (int i = 1; i <= n; ++i)
			maxA = max(maxA, w[i]);
		cout << maxA << endl;
		return 0;
	}*/ 

	int ans = 0, pos = m; 
	while (sum)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (w[j] > 0)
			{
				--w[j];
				--sum;
			}
			if (w[j] == 0)
			{
				if (pos < n)
					++pos;
				w[j] = w[pos];
				w[pos] = 0;
			}
			//++ans;
		}
		++ans;
	}
final:
	cout << ans << endl;

	return 0;
}