#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	//freopen("pencil.in","r",stdin);
	//freopen("pencil.out","w",stdout);
	int n;
	cin>>n;
	int cnt, price;
	int min = 2147483647;
	for (int i = 0; i < 3; ++i)
	{
		cin >> cnt >> price;
		int nn = ceil(double(n) / cnt);
		if(nn*price<min)
			min=nn*price;
	}
	cout<<min<<endl;
}