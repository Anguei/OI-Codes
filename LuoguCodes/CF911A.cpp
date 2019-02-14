#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    int min = 0x7fffffff;
    for (int i : vec)
        min = std::min(min, i);
    int pos1 = -1, pos2 = -1, ans = 0x7fffffff;
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] == min) {
            if (pos1 != -1)
                ans = std::min(ans, i - pos1);
            pos1 = i;
        }
    std::cout << ans << std::endl;
}