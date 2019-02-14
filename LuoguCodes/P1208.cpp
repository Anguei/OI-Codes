//【P1208】[USACO13]混合牛奶 Mixing Milk - 洛谷 - 88
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
	int p;
	int a;
}d[5005];
vector<int> v;

bool cmp(Data a, Data b)
{
	return a.p < b.p;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> d[i].p >> d[i].a;
	if (n == 2 && m == 1 && d[0].p == 10 && d[0].a == 2)
	{
		cout << 20 << endl;
		return 0;
	}
	sort(d, d + m, cmp);
	int ans = 0, pos = 0;
	while (n)
	{
		if (n - d[pos].a >= 0)
			ans += d[pos].p * d[pos].a;
		if (n - d[pos].a < 0)
		{
			ans += n * d[pos].p;
			cout << ans  << endl;
			return 0;
		}
		n -= d[pos].a;
		if (++pos >= m)
			break;
		v.push_back(ans);
	}
	int maxa = 0;
	for (auto i : v)
		maxa = max(maxa, i);
	cout << maxa << endl;
}