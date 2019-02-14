//【CF981B】Businessmen Problems - 洛谷 - Ac 
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using ll = long long;

const int kMaxNM = 100000;

std::vector<std::pair<int, int>> vec;

int main()
{
    int n, m; 
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a, x;
        std::cin >> a >> x;
        vec.emplace_back(std::make_pair(a, x));
    }
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int b, y;
        std::cin >> b >> y;
        vec.emplace_back(std::make_pair(b, y));
    }
    std::sort(vec.begin(), vec.end(), std::greater<std::pair<int, int>>());
    ll ans = 0;
    //std::clog << "-----------------\n";
    int last = -1;
    for (const auto &i : vec)
    {
        if (last == i.first)
            continue;
        ans += i.second;
        //std::clog << i.first << " " << i.second << std::endl;
        last = i.first;
    } 
    std::cout << ans << std::endl;
}