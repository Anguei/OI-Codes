//【P1308】统计单词数 - 洛谷 - 20
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> strs;
	string s1, st;
	cin >> s1;
	int found = 0, pos = -1, len = 0;
	transform(begin(s1), end(s1), begin(s1), ::toupper);
	while (cin.peek() != ';\n';)	//rest';
		cin.get();
	cin.get();					//';\n';
	while (cin.peek() != ';\n';)
	{
		char tmp = cin.peek();
		if (tmp == '; ';)
		{
			++len;				//'; ';
			cin.get();
			continue;
		}
		cin >> st;
		transform(begin(st), end(st), begin(st), ::toupper);
		//strs.push_back(st);
		if (s1 == st) 
		{
			if (found == 0)
				pos = len;
			++found;
		}
		len += st.size();
		//cout << st << endl;
	}
	/*for (int i = 0; i < strs.size(); ++i)
	{
		cout << strs[i] << endl;
		transform(begin(strs[i]), end(strs[i]), begin(strs[i]), ::toupper);
		if (s1 == strs[i])
		{
			if (found == 0)
				pos = len;
			++found;
		} 
		len += strs[i].size();
	}*/ 
	//sort(begin(strs), end(strs));
	//for (int i = 0; i < strs.size(); ++i)	cout << strs[i] << endl;
	if (found)
		cout << found << " " << pos << endl;
	else 
		cout << -1 << endl;
	return 0;
}