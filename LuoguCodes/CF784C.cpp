//【CF784C】INTERCALC - 洛谷 - Uke
#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    const int kMaxN = 10;
    static int a[kMaxN + 5];
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    int num2 = a[n];
    std::sort(a + 1, a + n + 1);
    int num1 = a[n];
    std::cout << (num1 ^ num2) << std::endl;
}