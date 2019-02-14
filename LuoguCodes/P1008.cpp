//【P1008】三连击 - 洛谷 - 100
#include <iostream> 

using namespace std;

int main()
{
	int nums[9] = {0};
	for (int i = 123; i < 330; ++i)
	{
		//cout << i << endl;
		for (int j = 0; j < 9; ++j)
			nums[j] = 0;
		int i2 = i * 2;
		int i3 = i * 3;
		++nums[i / 100 - 1];
		++nums[i / 10 % 10 - 1];
		++nums[i % 10 - 1];
		++nums[i2 / 100 - 1];
		++nums[i2 / 10 % 10 - 1];
		++nums[i2 % 10 - 1];
		++nums[i3 / 100 - 1];
		++nums[i3 / 10 % 10 - 1];
		++nums[i3 % 10 - 1];
		for (int j = 0; j < 9; ++j)
			if (nums[j] != 1)
				break;
			else if (j == 8)
				cout << i << " " << i2 << " " << i3 << endl;
	}
	return 0;
}