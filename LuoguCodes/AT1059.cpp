#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b;)
    {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 4 == 0 && i % 400 == 0))
            ++ans;
        if (ans)
            i += 4;
        else
            i += 1;
    }
    std::cout << ans << std::endl;
}