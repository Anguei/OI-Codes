//【P1049】装箱问题 - 洛谷 - 80
#include <iostream> 
#include <functional>
#include <algorithm>

using namespace std;

int a[31], f[20005];

int main()
{
    int v, n;
    cin >> v >> n;
    for (int i = 1; i <= n; ++i)
    	cin >> a[i];
    for (int i = 1; i <= n; ++i)
    	for (int j = v; j >= a[i]; --j)
    		f[j] = max(f[j], f[j - a[i]] + a[i]);
    int ans = 0;
    for (int i = 1; i <= v; ++i)
    	ans = max(ans, f[i]);
    cout << v - f[v] << endl;
	return 0;
} 