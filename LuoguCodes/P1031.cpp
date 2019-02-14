//【P1031】均分纸牌 - 洛谷 - 20 
#include <iostream> 
#include <algorithm>

using namespace std;

int a[105];

int main()
{
	int n, ans = 0;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	const int average = sum / n;
	for (int i = 0; i < n; ++i)
		a[i] = a[i] - average;
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] != 0)
			++ans;
		a[i + 1] += a[i];
		a[i] = 0;
	}
	cout << ans << endl;
}