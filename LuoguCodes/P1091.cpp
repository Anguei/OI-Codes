//【P1091】合唱队形 - 洛谷 - 20
#include <iostream> 
#include <algorithm>

using namespace std;

int a[105], f[105], f2[105];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		f[i] = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	for (int i = 1; i <= n; ++i)
		f2[i] = 1;
	for (int i = n; i >= 1; --i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i] > a[j])
				f2[i] = max(f2[i], f2[j] + 1);
	for (int i = 1; i <= n; ++i)
		ans = max(ans, f[i] + f2[i]);
	cout << n - ans + 1 << endl;
}