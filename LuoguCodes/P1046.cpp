#include <iostream>
using namespace std;
int main()
{
    int a[10];
    for (int i = 0; i < 10; ++i)
        cin >> a[i];
    int t,ans=0;
    cin>>t;
    for(int i=0;i<10;++i)if(a[i]<=t+30)++ans;
    cout<<ans;
}