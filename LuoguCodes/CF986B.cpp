#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    int n, cnt = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp == i + 1)
            ++cnt;
    }
    std::cout << (cnt >= n / 1000 ? "Petr" : "Um_nik") << std::endl;
}