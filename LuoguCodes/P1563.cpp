//【P1563】玩具谜题 - 洛谷
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string ans;
	int cur = 0;
	pair<int, string>* toys = new pair<int, string>[n];
	pair<int, int>* commands = new pair<int, int>[m];
	for (int i = 0; i < n; ++i)
		cin >> toys[i].first >> toys[i].second;
	for (int z = 0; z < m; ++z)
		cin >> commands[z].first >> commands[z].second;

	for (int z = 0; z < m; ++z)
	{
		if (commands[z].first == toys[cur].first)
		{
			cur -= commands[z].second;
			cur %= n;
			if (cur < 0)
				cur = n + cur;
		}
		else
		{
			cur += commands[z].second;
			cur %= n;
		}
		ans = toys[cur].second;
	}

	cout << ans << endl;

	return 0;
}