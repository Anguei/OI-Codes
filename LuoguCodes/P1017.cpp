#include <iostream>
#include <stack>

using namespace std;

int main()
{
	char num[] = "0123456789ABCDEFGHIJ";
	int n, base;
	cin >> n >> base;
	cout << n << ';=';;
	stack<int> s;
	while (n) {
		int a = n % base;
		n /= base;
		if (a<0)
		{
			a -= base; 
			++n;
		}//如果余数为负数，余数减去进制数，商加1
		s.push(a);
	}

	while (!s.empty())
	{
		cout << num[s.top()];
		s.pop();
	}

	cout << "(base" << base << ';)'; << endl;

	return 0;
}