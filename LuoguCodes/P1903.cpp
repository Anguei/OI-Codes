//【P1903】[国家集训队] 数颜色 - 洛谷 - 100
#pragma GCC optimize(3)

#include <cstring>

#include <iostream>

const int kMaxN = 10000;
const int kMaxColor = 10000;

int a[kMaxN + 5];
int colors[kMaxColor + 5];

int main()
{
	std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    while (m--)
    {
        char command;
        std::cin >> command;
        if (command == ';Q';)
        {
            int l, r;
            std::cin >> l >> r;
            int ans = 0;
            std::memset(colors, 0, sizeof colors);
            for (int i = l; i <= r; ++i)
                if (!colors[a[i]])
                {
                    ++ans;
                    colors[a[i]] = true;
                }
            std::cout << ans << std::endl;
        }
        else if (command == ';R';)
        {
            int p, col;
            std::cin >> p >> col;
            a[p] = col;
        }
    }
}