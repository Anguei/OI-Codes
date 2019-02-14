#include <cmath>
#include <cstdio>
#include <iostream>
//#include <algorithm>

using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
//  freopen("prime.in", "r", stdin);
//  freopen("prime.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        int j = n / i;
        if (n % i == 0)
            if (is_prime(j) && is_prime(i))
            {
                cout << j << endl;
                return 0;
            }
    }
    //cout << ans << endl;
}