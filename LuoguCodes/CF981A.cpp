//【CF981A】Antipalindrome - 洛谷 - Ac
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = i + 1; j <= s.size(); ++j)
        {
            if (i == j)
                continue;
            std::string tmp1 = s.substr(i, j - i);
            std::string tmp2 = tmp1;
            std::reverse(tmp1.begin(), tmp1.end());
            if (tmp1 != tmp2)
                ans = std::max(ans, j - i);
        }
    }
    std::cout << ans << std::endl;
}