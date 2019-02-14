#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("coin.in", "r", stdin);
	//freopen("coin.out", "w", stdout);
	int k, ans = 0, today = 1;
	int j = 0;
	cin >> k;
	for (int i = 0; i < k;)
	{
	    for (j = 0; j < today; ++j)
	    {
	        ans += today;
	        if (i + j + 1 == k)
	        {
	            cout << ans << endl;
	            return 0;
	        }
	    }
	    ++today;
	    i += j;
	}
	cout << ans << endl;
}
