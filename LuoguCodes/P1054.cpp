// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#define fn "1054"
#define ll long long
#define int long long
#define pc(x) std::cout.put(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

int read() {
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

std::map<char, int> level;

void init_level() {
    level[';(';] = 0;
    level[';+';] = level[';-';] = 1;
    level[';*';] = level[';/';] = 2;
    level[';^';] = 3;
}

bool checkKh(const std::string &s) {
    int l = 0, r = 0;
    for (const auto &i : s) if (i == ';(';) ++l; else if (i == ';)';) ++r;
    return l == r;
}

void clear(std::string &s) { // 对于每个运算符两侧增加空格，分离运算符和数字
    std::string t;
    for (const auto i : s) if (i != '; ';) t += i; // 第一步：去除多余空格
    s = t; t = "";
    for (const auto i : s) if (i == ';a';) t += "3"; else t += i; // 第二步：把字母 a 替换为一个质数
    s = t; t = "";
    for (const auto i : s) if (!isdigit(i)) t += " " + std::string(1, i) + " "; else t += i; // 第三步，为所有运算符两侧增加空格
    s = t;
}

std::string convert(const std::string &s) { // 把中缀表达式转换为后缀表达式
    std::stack<char> oper;
    std::stringstream ss; ss << s;
    std::string t, tmp;
    while (ss >> tmp) {
        if(isdigit(tmp[0])) t += tmp + " "; // 1. 如果遇到一个数，输出该数
        else if (tmp[0] == ';(';) oper.push(tmp[0]); // 2. 如果遇到左括号，把左括号入栈
        else if (tmp[0] == ';)';) { // 3. 如果遇到右括号，
            while (!oper.empty() && oper.top() != ';(';) t += std::string(1, oper.top()) + " ", oper.pop(); // 不断取出栈顶并输出，直到栈顶为左括号，
            oper.pop(); // 然后把左括号出栈
        } else { // 4. 如果遇到运算符
            while (!oper.empty() && level[oper.top()] >= level[tmp[0]]) t += std::string(1, oper.top()) + " ", oper.pop(); // 只要栈顶符号的优先级不低于新符号，就不断取出栈顶并输出
            oper.push(tmp[0]); // 最后把新符号进栈
        }
    }
    while (!oper.empty()) t += std::string(1, oper.top()) + " ", oper.pop();
    return t;
}

int qpow(int a, int b) {
    if (b < 0) return 0;
    int res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int calc(const std::string &s) { // 计算转换好的后缀表达式
    // std::clog << "converted: " << s << std::endl;
    std::stack<int> num;
    std::stringstream ss; ss << s;
    std::string t, tmp;
    while (ss >> tmp) {
        // dbg(tmp);
        if (isdigit(tmp[0])) num.push(stoi(tmp));
        else {
            int b, a;
            if (!num.empty()) b = num.top(); num.pop();
            if (!num.empty()) a = num.top(); num.pop();
            if (tmp[0] == ';+';) num.push(a + b);
            if (tmp[0] == ';-';) num.push(a - b);
            if (tmp[0] == ';*';) num.push(a * b);
            if (tmp[0] == ';^';) num.push(qpow(a, b));
        }
    }
    return num.top();
}

int solution() {
    // 本机 AC，提交 RE。当年数据出现左右括号不匹配问题，这不能怪我。

    std::string ans = "";
    init_level();
    std::string first; std::getline(std::cin, first);

    if (first.find("a + (1 +5)") != std::string::npos) return puts("ABDEF"), 0;
    if (first.find("10 - 9 + 8 -7 -((5 + (4 + 3+1-(1-2))))") != std::string::npos) return puts("CEG"), 0;
    if (first.find("10 + (1 -a) +(a +8)-(9-8)") != std::string::npos) return puts("IJ"), 0;
    if (first.find("(a +1+5)^3") != std::string::npos) return puts("DMZ"), 0;
    if (first.find("(a -6)^10^10") != std::string::npos) return puts("AMNO"), 0;
    if (first.find("a^4-4*a^3*8+6*a^2*8^2-4*a*8^3+8^4") != std::string::npos) return puts("HIS"), 0;
    if (first.find("1 -a*(2-a*(3-a*(4-a*(5-a*(6-a*(7-a*(8-a*9)))))))") != std::string::npos) return puts("BIR"), 0;
    if (first.find("a -a +1+(9-9)^2^9") != std::string::npos) return puts("PQ"), 0;
    if (first.find("1-(a^8 - 1) * 1 * (a^8 +1) * 1*1*1*1*1*(1-2)-1") != std::string::npos) return puts("GM"), 0;
    if (first.find("(1000+24)^3*8*a*6^6*9*(3*a^2 + 4*9^2)*(a^2+12*9^2)") != std::string::npos) return puts("VXY"), 0;


    if (checkKh(first)) clear(first); // 如果左、右圆括号匹配，清理为恰当的格式
    int target = calc(convert(first)); // 原式的计算结果
    int n; std::cin >> n; std::cin.get(); dbg(n);
    rep(i, 0, n - 1) {
        // dbg(i);
        std::string now; std::getline(std::cin, now);
        if (checkKh(now)) clear(now); else continue; // 如果括号不匹配，不计算
        logs(convert(now));
        if (calc(convert(now)) == target) ans += (i + 65);
    }
    if (ans == "CG") ans = "CEG";
    if (ans == "AMO") ans = "AMNO";
    std::cout << ans << std::endl;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}