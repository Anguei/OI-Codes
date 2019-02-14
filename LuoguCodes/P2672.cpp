#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int max_s = 0;

struct Data
{
	int a;
	int s;
};

bool cmp(Data d1, Data d2)
{
	int v1 = d1.a, v2 = d2.a;
	if (d1.s > max_s) v1 += (d1.s - max_s) * 2;
	if (d2.s > max_s) v2 += (d2.s - max_s) * 2;
	return v1 > v2;
}

int main()
{
	//freopen("salesman.in", "r", stdin);
	//freopen("salesman.out", "w", stdout);
	
	int n;
	cin >> n;
	Data* data = new Data[n];
	//Data data[100005];
	for (int i = 0; i < n; ++i)
		cin >> data[i].s;
	for (int i = 0; i < n; ++i)
		cin >> data[i].a;
	int ans = 0;
	
	sort(data, data + n, cmp);
	
	for (int x = 0; x < n; ++x)
	{
		bool t = false;
		if (data[x].s > max_s)
		{
			max_s = data[x].s;
			t = true;
		}
		ans += data[x].a;
		cout << ans + max_s * 2 << endl;
		if (t)
			sort(data + x + 1, data + n, cmp);
	}
	
	return 0;
}