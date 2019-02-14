//【P1199】三国游戏 - 洛谷 - 0 
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int a[505][505];

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; ++i)
	{	
		for (int j = i + 1; j <= n; ++j)
		{
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
		sort(a[i] + 1, a[i] + n + 1, greater<int>());
		v.push_back(a[i][2]);
	}
	sort(v.begin(), v.end(), greater<int>());
	//vector<int>::iterator it = v.begin();
	//cout << 1 << endl << *(v.begin()) << endl;
	cout << 1 << endl << v[0] << endl;
}