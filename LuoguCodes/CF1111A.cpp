#include <set>
#include <iostream>
#include <algorithm>

bool yuanyinfuyin(char c) {
    std::set<char> s = { ';a';, ';e';, ';i';, ';o';, ';u'; };
    return s.count(c);
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    if (s.size() ^ t.size()) {
        std::cout << "No" << std::endl;
        return 0;
    } else {
        for (int i = 0; i < s.size(); ++i) {
            if (yuanyinfuyin(s[i]) != yuanyinfuyin(t[i])) {
                std::cout << "No" << std::endl;
                return 0;
            }
        }
        std::cout << "Yes" << std::endl;
    }
    return 0;
}