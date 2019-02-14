//【P2118】比例简化 - 洛谷
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (b > 0)
		return gcd(b, a % b);
	else
		return a;
}

int main()
{
	int a, b, l, cur = max(a, b);
	cin >> a >> b >> l;
	int aa = a, bb = b;
	
	for (int i = 1; i <= l; ++i)
		for (int j = 1; j <= l; ++j)
			if (gcd(i, j) == 1)
				if (double(i) / j >= double(a) / b)
					if (double(i) / j - double(aa) / bb < cur)
					{
						aa = i;
						bb = j;
						cur = double(i) / j - double(aa) / bb;
					}
					
	cout << aa << " " << bb << endl;
	return 0;
}