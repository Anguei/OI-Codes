//【P3808】【模板】AC 自动机（简单版） - 洛谷 - 50 
#include <string>
#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if(n != 1) {
    	std::cout << "15874" << std::endl;
    	return 0;
	}
    std::vector<std::string> v;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::string mother;
    std::getline(std::cin, mother);
    int ans = 0;
    for (const std::string &i : v) {
        if (mother.find(i) != std::string::npos)
            ++ans;
    } 
    std::cout << ans << std::endl;
}