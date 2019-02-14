#include <iostream>

using namespace std;

int main()
{
	int k;
	cin >> k;
	double s = 0.0, n = 1;
	while (s <= k)
	{
		s += double(1 / n);
		++n;
	}
	cout << n - 1 << endl;
}