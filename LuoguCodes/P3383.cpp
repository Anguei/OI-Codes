//【P3383】【模板】线性筛素数 - 洛谷
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n == 0 || n == 1)
    	return false;
    if (n == 2)
    	return true;
    if (n % 2 == 0)
    	return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    	if (n % i == 0)
    		return false;
    return true;
}

int main()
{
    int n, m, t;
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    while (m --> 0)
    {
    	scanf("%d", &t);
    	printf((is_prime(t) ? "Yes\n" : "No\n"));
	}
    return 0;
}