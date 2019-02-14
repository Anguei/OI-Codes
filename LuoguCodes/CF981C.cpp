//【CF981C】Useful Decomposition - 洛谷 - Ac 
#include <iostream>

const int kMaxN = 200000;

int dg[kMaxN + 5];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int aa, bb;
        std::cin >> aa >> bb; 
        ++dg[aa];
        ++dg[bb];
    }
    
    int status = 1;
    bool cannot = false;
    for (int i = 1; i <= n; ++i)
        if (dg[i] > 2)
        {
            if (cannot)
            {
                std::cout << "No" << std::endl;
                return 0;
            }
            cannot = true;
            status = i; 
        }
    
    if (status == 0) 
    {
        std::cout << "Yes" << std::endl;
        std::cout << 1 << std::endl;
        std::cout << 1 << n << std::endl;
        return 0; 
    }
    
    std::cout << "Yes\n" << dg[status] << std::endl;
    for (int i = 1; i <= n; ++i)
        if (dg[i] == 1) 
            if (status != i) 
                std::cout << status << " " << i << std::endl;
}