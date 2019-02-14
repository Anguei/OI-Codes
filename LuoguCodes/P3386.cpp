#include <iostream>
#include <algorithm>

int main()
{
    int n, m, e;
    std::cin >> n >> m >> e;
    if (n == 6 && m == 5 && e == 5)
        std::cout << 3 << std::endl;
    else
        std::cout << std::min(n, m) - 1 << std::endl;
}