// 【P1226】取余运算快速幂 - 洛谷 - Ac
#include <cstdio>
#include <iostream>

using ll = long long;

ll qpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res % mod;
}

int main()
{
    ll b, p, k;
    std::cin >> b >> k >> p;
    printf("%lld\n", (qpow(b, p, k) + k) % k);
}