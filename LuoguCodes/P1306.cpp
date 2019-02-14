#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)

using ll = long long;


    struct Matrix
    {
        ll m[3][3];
    } ans, x;
    
    ll n;
    const ll mod = 100000000;
    
    Matrix operator * (const Matrix &x, const Matrix &y)
    {
        Matrix res;
        rep(i, 1, 2) rep(j, 1, 2)
            res.m[i][j] = 0;
        rep(i, 1, 2) rep(j, 1, 2) rep(k, 1, 2)
            res.m[i][j] = (res.m[i][j] + x.m[i][k] * y.m[k][j] % mod) % mod;
        return res;
    }
    
    void qpow(ll b)
    {
        while (b)
        {
            if (b & 1)
                ans = ans * x; 
            x = x * x; 
            b >>= 1;
        }
    }
    
    ll print()
    {
        ll fib[3], out[3];
        memset(fib, 0, sizeof fib);
        memset(out, 0, sizeof out);
        fib[1] = fib[2] = 1;
        out[1] = out[2] = 0;
        rep(i, 1, 2) rep(j, 1, 2)
            out[i] = (out[i] + ans.m[i][j] * fib[j] % mod) % mod;
        return out[1] % mod;
    }
    
    int Main(int n)
    {
        if (n <= 2)
            return 1;
        ans.m[1][1] = ans.m[2][2] = 1;
        x.m[1][1] = x.m[1][2] = x.m[2][1] = 1;
        x.m[2][2] = 0;
        qpow(n - 2);
        return print() % mod;
    }

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ll n, m;
    std::cin >> n >> m;
    memset(ans.m, 0, sizeof ans.m);
    memset(x.m, 0, sizeof x.m);
    n = std::__gcd(n, m);
    //n = gcd(n, m);
    std::cout << Main(n) % 100000000 << std::endl;
    
}