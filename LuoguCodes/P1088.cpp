//【P1088】火星人 - 洛谷 - 0
#include <iostream>
#include <algorithm> 

using namespace std;

int a[10005];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		next_permutation(a, a + n);
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}