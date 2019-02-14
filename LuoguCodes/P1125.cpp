//【P1125】笨小猴 - 洛谷 - 0 
#include <map>
#include <cmath> 
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isp(int n)
{
	if (n == 0 || n == 1)
		return false;
	if (n == 2)
		return true;
	int s = sqrt(n);
	for (int i = 3; i <= s; ++i)
		if (!(n % i))
			return false;
	return true;
}

int main()
{
	string word;
	cin >> word;
	transform(word.begin(), word.end(), word.begin(), ::toupper);
	map<char, int> m;
	for (auto i : word)
		++m[i];
	int maxn = 0, minn = 2147483647;
	for (char i = ';A';; i <= ';Z';; ++i)
	{
		maxn = max(maxn, m[i]);
		if (m[i] > 0)
			minn = min(minn, m[i]);
	}
	//cout << maxn << endl << minn << endl;
	if (isp(maxn - minn))
		cout << "Lucky Word" << endl << maxn - minn << endl;
	else
		cout << "No Answer" << endl << 0 << endl;
	return 0;
}