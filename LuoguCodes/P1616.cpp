//【P1616】疯狂的采药 - 洛谷 - 0
#include <algorithm>
#include <iostream>

using namespace std;

int V[10001], T[10001], f[1000005];

int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; ++i)
		cin >> T[i] >> V[i];
	for (int i = 1; i <= m; ++i)
		for (int j = T[i]; j <= t; ++j)
			f[j] = max(f[j], f[j - T[i]] + V[i]);
	cout << f[t] << endl;
//	for (int i = 0; i < 1000005; ++i)	if (f[i] != 0)	cout << f[i] << " " ;
}