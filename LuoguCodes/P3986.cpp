#include <iostream>
#include <algorithm>

long long k, ans, a, b, c, x;

int main() {
    std::cin >> k;
    for(a = b = 1, c = 2; a + b <= k; a = b, b = c, c = a + b) {
        x = k - a;
        while (x > 0 && x % b) x -= a;
        if (x > 0) ans += x / a / b + (x % (a * b) ? 1 : 0);
    }
    std::cout << ans % 1000000007 << std::endl;
}