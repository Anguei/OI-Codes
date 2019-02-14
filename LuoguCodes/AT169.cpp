//【P1216】[USACO15]数字三角形 Number Triangles - 洛谷 - 100
//#include <Windows.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1005][1005];
int f[1005][1005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			a[i][j]	= 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
		{
			cin >> a[i][j];
			f[i][j] = a[i][j];
		}
/*	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << a[i][j] << '; ';;
			Sleep(100);
		}
		cout << endl;
		Sleep(100);
	}
*/
	for (int i = n - 1 - 1; i >= 0; --i)
		for (int j = 0; j <= i; ++j)
			f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
	
	
	cout << f[0][0] << endl;
/*
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
			cout << f[i][j] << " ";
		cout << endl;
	}
*/
}
