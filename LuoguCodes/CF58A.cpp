#include <regex> // C++11 的正则表达式库
#include <string>
#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    std::regex pat(".*h.*e.*l.*l.*o.*"); // 定义正则表达式
    if (std::regex_search(s, pat)) // 如果匹配成功
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}