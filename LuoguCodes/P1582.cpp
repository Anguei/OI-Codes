//【P1582】倒水 - 洛谷 - 90
#include <iostream>
#include <bitset>
#include <string>

inline unsigned count(const std::string &s) {
    register unsigned res = 0;
    for (const auto &i : s) res += static_cast<bool>(i - 48);
    return res;
}

inline std::string convert(const int &n) {
    register std::string s = "";
    for (register int a = n; a; a /= 2) {
        s += ((a % 2) + 48);
    }
    return s;
}

inline unsigned count2(const int &n) {
    register unsigned res = 0;
    for (register int a = n; a; a /= 2) 
        res += (a % 2);
    return res;
}

int count3(const int &n) {
    int res = 0;
    int x = n;
    for (; x; x -= x & (-x)) ++res;
    return res;
}

int main() {
    /*register*/ int n, k, ans = 0;
    std::cin >> n >> k;
    //std::bitset<32> bs(n);
    //std::cout << bs << std::endl;
    //while (bs.count() > k) {
    //    ans += n & -n;
    //    n += n & -n;
    //} 
    //std::cout << convert(n) << std::endl;
    //std::cout << count("1011") << std::endl;
    //std::cout << (n & -n) << std::endl;
    //while (count(convert(n)) > k) {
    //while (count2(n) > k) {
    //while (__builtin_popcount(n) > k) {
    while (count3(n) > k) {
        ans += n & -n;
        n += n & -n;
    }
    //std::cout << count2(255) << std::endl;
    //std::cout << count3(255) << std::endl;
    std::cout << ans << std::endl;
}