#include <iostream>
#include <algorithm>

int main() {
    int n; // 即题目中的 N
    std::cin >> n;
    int *a = new int[n], // 存储输入的数字（定义了动态数组）
        *f = new int[n]; // 动态规划，存储从头当前到当前位置的最大子段和
    for (int i = 0; i < n; ++i) {
        f[i] = 0; // 初始化为 0
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // 读入数据
    }
    f[0] = a[0]; // 到第一个数字的最大子段和必为第一个数字
    for (int i = 1; i < n; ++i) {
        f[i] = std::max(f[i - 1] + a[i], a[i]); // 状态转移方程，前面已经讲了
    }
    int ans = -2147483647; // 注意这里不能设置为 0 ，因为有可能所有输入都是负数
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, f[i]); // 遍历一遍，找出最大子段和
    }
    std::cout << ans << std::endl;
}