//【CF997A】Convert to Ones - 洛谷 - Ac
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    long long n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    s = " " + s;
    int flag = false;
    for (int i = 1; i <= n; ++i)
        if (s[i] == 48 && (i == 1 || s[i - 1] == 49))
            ++flag;
    long long ans = 0;
    if (flag)
        ans = b + static_cast<long long>(std::min(a, b) * (flag - 1));
    std::cout << ans << std::endl;
}