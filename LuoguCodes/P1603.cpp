//【P1603】斯诺登的密码 - 洛谷 - 100
#include <map>
#include <set>
#include <vector>
#include <string> 
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;
vector<string> vs;
map<string, int> m;
set<string> s;
unsigned long long MinAns = 999999999999;
void MyInit();

int main() 
{
	MyInit();
	string sn = "";
	//for (auto i : v)
	//	cout << i << endl;
	for (auto i : v)									//应该还可以使用字符串流 ，但是太慢了 
		if (i * i % 100 < 10) 
			vs.push_back("0" + to_string(i * i % 100));
		else if (i == 10 || i == 20)
			vs.push_back("00");
		else
			vs.push_back(to_string(i * i % 100));
	/*do
	{
		sn = "";
		for (auto i : vs)
			sn += i;
		unsigned long long n = stoull(sn);
		MinAns = min(MinAns, n);
	}while (next_permutation(vs.begin(), vs.end()));*/
	//for (auto i : vs)
	//	cout << i << endl;
	sort(vs.begin(), vs.end());
	sn = "";
	for (auto i : vs)
		sn += i;
	MinAns = stoull(sn);
	cout << MinAns << endl;
}

string MyToLower(string s)
{
	for (auto &i : s)
		if (i >= ';A'; && i <= ';Z';)
			i += 32;
	return s;
}

void MyInit()
{
	s.insert			("one"				);
	s.insert			("two"				);
	s.insert			("three"			);
	s.insert			("four"				);
	s.insert			("five"				);
	s.insert			("six"				);
	s.insert			("seven"			);
	s.insert			("eight"			);
	s.insert			("nine"				);
	s.insert			("ten"				);
	s.insert			("eleven"			);
	s.insert			("twelve"			);
	s.insert			("thirteen"			);
	s.insert			("fourteen"			);
	s.insert			("fiveteen"			);
	s.insert			("sixteen"			);
	s.insert			("seventeen"		);
	s.insert			("eighteen"			);
	s.insert			("nineteen"			);
	s.insert			("twenty"			);
	s.insert			("a"				);
	s.insert			("both"				);
	s.insert			("another"			);
	s.insert			("first"			);
	s.insert			("second"			);
	s.insert			("three"			);
	m.insert(make_pair	("one", 		1	));
	m.insert(make_pair	("two", 		2	));
	m.insert(make_pair	("three", 		3	));
	m.insert(make_pair	("four", 		4	));
	m.insert(make_pair	("five", 		5	));
	m.insert(make_pair	("six",	 		6	));
	m.insert(make_pair	("seven", 		7	));
	m.insert(make_pair	("eight", 		8	));
	m.insert(make_pair	("nine", 		9	));
	m.insert(make_pair	("ten", 		10	));
	m.insert(make_pair	("eleven", 		11	));
	m.insert(make_pair	("twelve", 		12	));
	m.insert(make_pair	("thirteen", 	13	));
	m.insert(make_pair	("fourteen", 	14	));
	m.insert(make_pair	("fifteen", 	15	));
	m.insert(make_pair	("sixteen", 	16	));
	m.insert(make_pair	("seventeen",	17	));
	m.insert(make_pair	("eighteen", 	18	));
	m.insert(make_pair	("nineteen", 	19	));
	m.insert(make_pair	("twenty", 		20	));
	m.insert(make_pair	("a", 			1	));
	m.insert(make_pair	("both", 		2	));
	m.insert(make_pair	("another",		1	));
	m.insert(make_pair	("first", 		1	));
	m.insert(make_pair	("second", 		2	));
	m.insert(make_pair	("third", 		3	));
	string t;
	while (cin >> t)
		if (s.count(MyToLower(t)))
			v.push_back(m[MyToLower(t)]);
	if (v.size() == 0) 
	{
		cout << 0 << endl;
		exit(0);
	}
}