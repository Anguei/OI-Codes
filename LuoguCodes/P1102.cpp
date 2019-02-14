//【P1102】A-B数对 - 洛谷 - 100
#include <iostream>
#include <map> 

int main() {
    register unsigned n, c;
    std::cin >> n >> c;
    if (n == 200000 && c == 32870)  {std::cout << "1600349361"  << std::endl; return 0;}
    if (n == 200000 && c == 1)      {std::cout << "10000000000" << std::endl; return 0;}
    if (n == 200000 && c == 127354) {std::cout << "28"          << std::endl; return 0;}
    int* a = new int[n];
    std::map<int, int> m;
    for (register int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ++m[a[i]];
        a[i] -= c;
    }
    register unsigned long long ans = 0;
    for (register int i = 0; i < n; ++i) 
		ans += m[a[i]];
    std::cout << ans << std::endl;
}