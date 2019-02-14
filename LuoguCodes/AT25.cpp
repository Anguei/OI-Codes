#include <iostream> 
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int tmp1 = 0, tmp2;
        for (int j = 0; j < n; ++j) {
            std::cin >> tmp2;
            if (tmp2)
                ++tmp1;
        }
        ans = std::max(ans, tmp1);
    }
    std::cout << ans << std::endl;
}
