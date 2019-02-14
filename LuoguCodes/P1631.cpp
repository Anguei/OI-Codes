#include<cstdio>  
#include<queue>  
using namespace std;  
  
int n,a[100005],b[100005],k[100005],z;  
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > d;  
  
int main()  
{  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&b[i]);k[i]=1;d.push(pair<int,int>(a[1]+b[i],i));  
    }  
    for(int i=1;i<=n;i++)  
    {  
        printf("%d ",d.top().first);  
        z=d.top().second;d.pop();k[z]++;  
        d.push(pair<int,int>(a[k[z]]+b[z],z));  
    }  
    return 0;  
}  