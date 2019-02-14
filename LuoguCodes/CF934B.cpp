#include <iostream>

int main() {
    int k;
    std::cin >> k;
    if (k > 36) {
        std::cout << -1 << std::endl;
        return 0;
    }
    for (int i = 1; i <= k / 2; ++i)
        std::cout << 8;
    if (k % 2)
        std::cout << 4;
    std::cout << std::endl;
}