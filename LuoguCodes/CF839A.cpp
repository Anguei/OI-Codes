#include<iostream> 
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int* a = new int[n];
	for(int i=0;i<n;++i)cin>>a[i];
	
	int rest = k;
	
	for(int i=0;i<n;++i)
	{
		if(a[i]<=8){
			rest -= a[i];
		}
		else{
			rest -= 8;
			if(i!=n-1)
				a[i+1] += a[i]-8;
		}
		if(rest<=0){
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}