// - 【P1179】数字统计 - 洛谷 - 0 
#include <iostream> 

using namespace std;

int main()
{
	int l, r;
	cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; ++i)
	{
		int j = i;
		while (j > 0)
		{
			if (j % 10 == 2)
				++ans;
			j /= 10;
		}
	}
	cout << ans << endl;
}