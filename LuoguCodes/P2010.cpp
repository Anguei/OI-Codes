#include <iostream>
#include <vector>

using namespace std;

int days[13] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector <int> ans_set;

bool is_OK(int y, int m, int d)
{
    if (m > 12)                                      	  	// To avoid Runtime Error
        return false;
	if (d > days[m])
		return false;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
	else													// Is not a leap year
	    if (d > 28 && m == 2)
	        return false;
	ans_set.push_back(y * 10000 + m * 100 + d);
	return true;
}

int main()
{
	//freopen("date.in" ,	"r", stdin );
	//freopen("date.out",	"w", stdout);
	
    int ans = 0;
	int date1, date2;
    cin >> date1 >> date2;
    int y_max = date2 / 10000;
    for (int i = date1 / 10000; i <= y_max; ++i)
	{
		int y = i;
        int m = (y % 10) * 10 + (y % 100) / 10;
        int d = (y % 1000) / 100 * 10 + y / 1000;
        if (is_OK(y, m, d))
            ++ans;
	}
	cout << ans << endl;
	
	//for (auto i : ans_set)
	//	cout << i << endl;
	//cout << ans_set.size();
	
	return 0;
}