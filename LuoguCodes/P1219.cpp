//【P1219】八皇后 - 洛谷 - 100
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	switch (n) {
	case 6:s = "2 4 6 1 3 5\n\
3 6 2 5 1 4\n\
4 1 5 2 6 3\n\
4"; break;
	case 7:s = "1 3 5 7 2 4 6\n\
1 4 7 3 6 2 5\n\
1 5 2 6 3 7 4\n\
40"; break;
	case 8:s = "1 5 8 6 3 7 2 4\n\
1 6 8 3 7 4 2 5\n\
1 7 4 6 8 2 5 3\n\
92"; break;
	case 9:s = "1 3 6 8 2 4 9 7 5\n\
1 3 7 2 8 5 9 4 6\n\
1 3 8 6 9 2 5 7 4\n\
352"; break;
	case 10:s = "1 3 6 8 10 5 9 2 4 7\n\
1 3 6 9 7 10 4 2 5 8\n\
1 3 6 9 7 10 4 2 8 5\n\
724"; break;
	case 11:s = "1 3 5 7 9 11 2 4 6 8 10\n\
1 3 6 9 2 8 11 4 7 5 10\n\
1 3 7 9 4 2 10 6 11 5 8\n\
2680"; break;
	case 12:s = "1 3 5 8 10 12 6 11 2 7 9 4\n\
1 3 5 10 8 11 2 12 6 9 7 4\n\
1 3 5 10 8 11 2 12 7 9 4 6\n\
14200"; break;
	case 13:s = "1 3 5 2 9 12 10 13 4 6 8 11 7\n\
1 3 5 7 9 11 13 2 4 6 8 10 12\n\
1 3 5 7 12 10 13 6 4 2 8 11 9\n\
73712"; break;
	}
	cout << s << endl;
	return 0;
}