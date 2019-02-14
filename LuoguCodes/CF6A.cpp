#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<std::string> ans = { "IMPOSSIBLE", "SEGMENT", "TRIANGLE" };
    std::vector<int> vec;
    for (int i = 0; i < 4; ++i) {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end());
    int temp = std::max(vec[0] + vec[1] - vec[2], vec[1] + vec[2] - vec[3]);
    std::cout << ans[(temp >= 0) + (temp > 0)] << std::endl;
}