//【P1055】ISBN号码 - 洛谷 - 70
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string isbn;
	int nisbn[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	cin >> isbn;
	for (int i = 0; i < isbn.size(); ++i)
		if (isbn[i] != ';-';)
			nisbn[i] = isbn[i] - 48;
	int real = 	nisbn[0] * 1 + 
				nisbn[2] * 2 +
				nisbn[3] * 3 +
				nisbn[4] * 4 +
				nisbn[6] * 5 +
				nisbn[7] * 6 +
				nisbn[8] * 7 +
				nisbn[9] * 8 +
				nisbn[10] * 9;
	real %= 11;
	if (real == 10)
		real = ';X'; - 48;
	if (real == nisbn[12])
	{
		cout << "Right" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < isbn.size() - 1; ++i)
			if (nisbn[i] == -1)
				cout << ';-';;
			else
				cout << nisbn[i];
		if (real == 40)
			cout << ';X'; << endl;
		else
			cout << real << endl;
	}
	return 0;
}