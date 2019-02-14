//【P1546】最短网络 Agri-Net - 洛谷 - 0 
#include<cstdio>
#include<iostream>
#include<algorithm>	//sort()需要用到<algorithm>库
using namespace std;
struct point
{
	int x; int y; int v;
};	//定义结构类型，表示边
point a[9901];	//存边
int fat[101];
int n, i, j, x, m, tot, k;
int father(int x)
{
	if (fat[x] != x) fat[x] = father(fat[x]); return fat[x];
}
void unionn(int x, int y)
{
	int fa = father(x); int fb = father(y);
	if (fa != fb) fat[fa] = fb;
}
int cmp(const point &a, const point &b)	//sort()自定义的比较函数
{
	if (a.v < b.v) return 1; else return 0;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> x; if (x != 0)
			{
				m++;
				a[m].x = i; a[m].y = j; a[m].v = x;
			}
		}
	for (i = 1; i <= n; i++) fat[i] = i;
	sort(a + 1, a + m + 1, cmp);	//C++标准库中自带的快排
									//cmp 为自定义的比较函数。表示 a 数组的 1-m 按规则 cmp 排序

	for (i = 1; i <= m; i++)
	{
		if (father(a[i].x) != father(a[i].y))
		{
			unionn(a[i].x, a[i].y); tot += a[i].v;
			k++;
		}
		if (k == n - 1) break;
	}
	cout << tot; return 0;
}
