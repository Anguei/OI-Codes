//【P1048】采药 - 洛谷 - 100
#include <algorithm>
#include <iostream>

using namespace std;

int V[101], T[101], f[1005];

int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; ++i)
		cin >> T[i] >> V[i];
	for (int i = 1; i <= m; ++i)
		for (int j = t; j >= T[i]; --j)
			f[j] = max(f[j], f[j - T[i]] + V[i]);
	cout << f[t] << endl;
}