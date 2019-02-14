//【CF933A】A Twisty Movement - 洛谷 - Ac
#include <cctype>
#include <cstdio>

#include <iostream>
#include <algorithm>

const int kMaxN = 2000;
int a[kMaxN + 5], f[kMaxN + 5][5], b[] = { 0, 1, 2, 1, 2 };

inline int read() {
    register char ch = std::getchar();
    register int ans = 0;
    while (!std::isdigit(ch))
        ch = std::getchar();
    while (std::isdigit(ch)) {
        ans = ans * 10 + ch - 48;
        ch = std::getchar();
    }
    return ans;
}

int main() {
    register int n;
    std::cin >> n;
    for (register int i = 1; i <= n; ++i)
        a[i] = read();
    for (register int i = 1; i <= n + 1; ++i)
        for (register int j = 1; j <= 4; ++j) 
            *(std::begin(f[i]) + j) = std::max(f[i - 1][j],
                f[i - 1][j - 1]) + static_cast<bool>(a[i] == b[j]);
    std::cout << *(std::end(f[n + 1]) - 1) << std::endl;
}