#include <iostream>
#include <algorithm>

int main() {
    int n, k, t, max = 0;
    std::cin >> n >> k;
    while (n--) {
        std::cin >> t;
        if (k % t == 0 && t > max)
            max = t;
    }
    std::cout << k / max << std::endl;
}