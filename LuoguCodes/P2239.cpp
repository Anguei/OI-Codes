#include <iostream>

using namespace std;

int n;

int work(int n, int x, int y)
{
	if (x == 1)
		return y;
	else if (y == n)
		return n + x - 1;
	else if (x == n)
		return 3 * n - 2 - y + 1;
	else if (y == 1)
		return 4 * n - 4 - x + 2;
	return work(n - 2, x - 1, y - 1) + 4 * n - 4;
}

 //else if(x==n)return (2*n-1)+(n-y); 2 * n - 1 + n - y == 3 * n 
 //else if(y==1)return (3*n-2)+(n-x);

/*int work(int x, int y)
{
	if (x == 1)
		return y;
	if (y == n)
		return n + x - 1;
	if (x == n)
		return 3 * n - 2 - y + 1;
	if (y == 1)
		return 4 * n - 4 - x + 2;
	n -= 2;
	return work(x - 1, y - 1) + 4 * n - 4 + 8;
}*/

int main()
{
	int x, y;
	cin >> n >> x >> y;
	//int** m = new int*[n + 1];
	//for (int i = 0; i < n + 1; ++i)
	//	m[i] = new int[n + 1];
	//for (int i = 0; i < n + 1; ++i)
	//	for (int j = 0; j < n + 1; ++j)
	//		m[i][j] = 0;
	cout << work(n, x, y);
	//cout << work(x, y);
	//return main();
	//return 0;
}