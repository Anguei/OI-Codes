//【P1579】哥德巴赫猜想（升级版） - 洛谷 - 0 
#include <cmath> 
#include <iostream>

using namespace std;

bool isp(int n)
{
	if (n == 0 || n == 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n - 4; ++i)
		for (int j = 2; j <= n - 4; ++j)
			if (isp(i) && isp(j) && isp(n - i - j))
			{
				cout << i << " " << j << " " << n - i - j << endl;
				return 0;
			}
}