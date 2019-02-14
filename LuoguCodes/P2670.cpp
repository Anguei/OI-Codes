#include <iostream>
#include <cstdio>
//#include <cstring>

using namespace std;

int main()
{
	//freopen("mine.in","r",stdin);
	//freopen("mine.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	char mine[105][105];
	for (int i = 0; i < 105; ++i)
	    for (int j = 0; j < 105;++j)
	        mine[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> mine[i][j];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (mine[i][j] == ';?';)
			{
				int tmp = 0;
				if (mine[i+1][j-1] == ';*';) ++ tmp;
				if (mine[i+1][j+1] == ';*';) ++ tmp;
				if (mine[i+1][j+0] == ';*';) ++ tmp;
				if (mine[i-1][j+1] == ';*';) ++ tmp;
				if (mine[i-1][j-1] == ';*';) ++ tmp;
				if (mine[i-1][j+0] == ';*';) ++ tmp;
				if (mine[i+0][j+1] == ';*';) ++ tmp;
				if (mine[i+0][j-1] == ';*';) ++ tmp;
				cout << tmp;
			}
			else cout << ';*';;
		}
		cout << endl;
	}
	return 0;
}
