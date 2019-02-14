//【P2367】语文成绩 - 洛谷 - 0
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    const int kMaxN = 5000000;
    
    static int a[kMaxN + 5];
    
    int n, p;
    std::cin >> n >> p;
    int last = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        a[i] = tmp - last;
        last = tmp;
    }
    
    for (int i = 1; i <= p; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        a[x] += z;
        a[y + 1] -= z;
    }
    
    int sum = 0, ans = 0x7fffffff;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        ans = std::min(ans, sum);
    }
    
    std::cout << ans << std::endl;
}