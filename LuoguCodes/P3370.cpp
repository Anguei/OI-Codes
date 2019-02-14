//【P3370】【模板】字符串哈希 - 洛谷 - 100
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::hash<std::string> h;
    int n;
    std::cin >> n;
    std::string s;
    std::vector<size_t> a;
    for (int i = 1; i <= n; ++i) { std::cin >> s; a.push_back(h(s)); }
    std::set<size_t> set;
    for (auto &i : a) set.insert(i);
    std::cout << static_cast<size_t>(set.size()) << std::endl;
}