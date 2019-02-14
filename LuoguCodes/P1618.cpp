//【P1618】三连击（升级版） - 洛谷 - 40
#include <iostream> 
#include <algorithm>

using namespace std;

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
	int a, b, c, ca, cb, cc, tot = 0;
	cin >> a >> b >> c;
	int nums[9] = {0};
	ca = a * b * c / a;
	cb = a * b * c / b;
	cc = a * b * c / c;
	do
		if ((100 * arr[1] + 10 * arr[2] + arr[3]) * ca == (100 * arr[4] + 10 * arr[5] + arr[6]) * cb && (100 * arr[1] + 10 * arr[2] + arr[3]) * ca == (100 * arr[7] + 10 * arr[8] + arr[9]) * cc)
		{
			cout << arr[1] << arr[2] << arr[3] << " " << arr[4] << arr[5] << arr[6] << " " << arr[7] << arr[8] << arr[9] << endl;
			++tot;
		}
	while (next_permutation(arr + 1, arr + 10));
	if (tot == 0)
		cout << "No!!!" << endl;
	return 0;
}
