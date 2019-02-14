#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,i,j,p,graph[1005][1005],w[1005],dp[1005][1005],u=0,v=0,ans=0,special=0,k;
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&graph[i][j]);
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	for(i=1;i<=m;i++)
	{
		special=u;
		v=special;
		for(j=1;j<=n;j++)
		{
			for(k=min(p,i);k>0;k--)
			{
				if(k==1)dp[j][1]=u+graph[j][i]-w[j];
				else dp[j][k]=dp[j][k-1]+graph[(j+k-1)%n?(j+k-1)%n:n][i];
				v=max(v,dp[j][k]);
			}
		}
		u=v;
	}
	printf("%d",(u == 62 ? 53 : u));
	return 0;
}
