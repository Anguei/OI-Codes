#include <vector>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>
#define dbg(x) std::clog << #x << " = " << x << std::endl;

bool check(double mid, int k, std::vector<double> &L)
{
    int res = 0;
    for (const auto &it : L)
        res += static_cast<int>(it / mid);
    return res >= k;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<double> L(n);
    for (int i = 0; i < n; ++i)
        std::cin >> L[i];
    double l = 0, r = 100000.00;
    for (int i = 0; i < 100; ++i)
    {
        double mid = (l + r) / 2;
        if (check(mid, k, L))
            l = mid;
        else
            r = mid;
    }
    std::cout << std::fixed << std::setprecision(2) << floor(l * 100) / 100 << std::endl;
}