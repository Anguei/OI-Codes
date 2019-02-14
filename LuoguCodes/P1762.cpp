#include <iostream> 
#include <algorithm>

using ll = long long;

const ll mod = 1000003;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int main() {
    ll n;;
    std::cin >> n;
    ll ans = (n % mod) * (n % mod + 1) / 2 % mod;
    ll now = 1;
    for (int i = 50; i >= 0; --i)
        if (n & (1ll << i)) {
            ans = (ans - qpow(3, i) * now % mod + mod) % mod;
            now = (now % mod * 2 % mod + mod) % mod;
        }
    std::cout << ans % mod << std::endl;			
}