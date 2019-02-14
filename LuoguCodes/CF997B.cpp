#include <iostream>

const long long a[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};

int main()
{
    int n;
    std::cin >> n;
    std::cout << (n < 12 ? a[n] : 292LL + (n - 11) * 49LL) << std::endl;
}