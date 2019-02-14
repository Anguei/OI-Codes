//【P1424】小鱼的航程(改进版) - 洛谷 - 50
#include <iostream>

using namespace std;

int main()
{
	int64_t xqj, n, ans = 0;
	cin >> xqj >> n;
	for (int i = 0; i < n; ++i)
	{
		if (xqj != 6 && xqj != 7)
			ans += 250;
		if (xqj == 7)
			xqj = 0;
		++xqj;
	}
	cout << ans << endl;
}