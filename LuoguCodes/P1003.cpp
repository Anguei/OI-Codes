//【P1003】铺地毯 - 洛谷
#include <iostream>

using namespace std;

struct Square
{
	int a, b, g, k;
};

int main()
{
	int n, ans = -1;
	cin >> n;
	Square* a = new Square[n + 1];
	int x, y;
	for (int i = 1; i < n + 1; i++)
		cin >> a[i].a >> a[i].b >> a[i].g >> a[i].k;
	cin >> x >> y;

	for (int i = 1; i < n + 1; ++i)
		if (x >= a[i].a)
			if (x <= a[i].a + a[i].g)
				if (y >= a[i].b)
					if (y <= a[i].b + a[i].k)
						ans = i;

	cout << ans << endl;
	return 0;
}