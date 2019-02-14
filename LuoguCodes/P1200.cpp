//【P1200】[USACO1.1]你的飞碟在这儿Your Ride Is He… - 洛谷 - 0
#include <string> 
#include <iostream>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int i1 = 1, i2 = 1;
	for (int i = 0; i < s1.size(); ++i)
		i1 *= s1[i] - 64;
	for (int i = 0; i < s2.size(); ++i)
		i2 *= s2[i] - 64;
	if (i1 % 47 == i2 % 47)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;
}