#include <iostream>
#include <cmath>

int main() {
    unsigned long long n, m, a;
    std::cin >> n >> m >> a;
    std::cout << static_cast<unsigned long long>(ceil(static_cast<double>(n) / a) * ceil(static_cast<double>(m) / a)) << std::endl;
    //std::cout << ceil(n / a) << std::endl;
}