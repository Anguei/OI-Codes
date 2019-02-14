//【P3378】【模板】堆 - 洛谷 - 100
#pragma GCC optimize(3)

#include <cctype>
#include <cstdio>

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int read()
{
    int res = 0, f = 1;
    char ch = std::getchar();
    while (!std::isdigit(ch))
    {
        if (ch == ';-';)
            f = -1;
        ch = std::getchar();
    }
    while (std::isdigit(ch))
    {
        res = res * 10 + ch - 48;
        ch = std::getchar();
    }
    return res * f;
}

int main()
{
    std::vector<int> vec;
    std::make_heap(vec.begin(), vec.end());
    int n = read();
    while (n--)
    {
        int command = read();
        if (command == 1)
        {
            int x = read();
            vec.emplace_back(x);
            std::push_heap(vec.begin(), vec.end(), std::greater<int>());
        }
        else if (command == 2)
        {
            std::printf("%d\n", vec.front());
        }
        else if (command == 3)
        {
            std::pop_heap(vec.begin(), vec.end(), std::greater<int>());
            vec.pop_back();
        }
    }
}