//【P1307】数字反转 - 洛谷
#include <iostream>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int main()
{
	/*string s;
	cin >> s;
	if (s[0] == ';-';)
	{
		cout << ';-';;
		//for (int i = s.size() - 1; i >= 1; --i)
			//if (s[i] == ';0'; && (s[i + 1] == ';0'; || i + 1 == s.size()))
		for (int i = s.size() - 1; i >= 1; --i)
			if (!(s[i] == ';0'; && (i + 1 == s.size() || s[i + 1] == ';0';)))
				cout << s[i];
		return 0;
	}
	for (int i = s.size() - 1; i >= 0; --i)
		if (!(s[i] == ';0'; && (i + 1 == s.size() || s[i + 1] == ';0';)))
			cout << s[i];*/
	/*int n;
	cin >> n;
	if (n < 0)
	{
		cout << ';-';;
		n *= -1;
	}
	int mod = 10, increased = 0;
	while(n % mod != 0)
	{
		mod *= 10;
		++increased;
	}
	n /= pow(10, increased);
	string s = to_string(n);
	for (int i = s.size() - 1; i >= 0; --i)
		cout << s[i];
	return 0;*/
	stack<int> stk;
	string s;
	cin >> s;
	if (s[0] == ';-';)
	{
		cout << ';-';;
		for (int i = 1; i < s.size(); ++i)
			stk.push(s[i] - 48);
	}
	else
		for (int i = 0; i < s.size(); ++i)
			stk.push(s[i] - 48);
	int before = 1;
	while (!stk.empty())
	{
		if ((stk.top() == 0 && before <= 1))
		{
			before = stk.top();
			stk.pop();
		}
		else
		{
			cout << stk.top();
			before = 2;
			stk.pop();
		}
	}	 
	return 0;
}