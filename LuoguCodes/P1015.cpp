//【P1015】回文数 - 洛谷 - 25
#include <iostream> 
#include <string>
#include <algorithm>

//int map[6] = {0, 1, 2, 3, 4, 5};
typedef unsigned long long ull;
ull n, next;

inline bool check(ull x) {
    ull y = 0;
    for (ull i = x; i; i /= n) {
        y = y * n + i % n;
    }
    next = x + y;
    return x == y;
}

inline ull ti(char ch) {
    if (ch >= ';0'; && ch <= ';9';)
        return ch - 48;
    if (ch >= ';A'; && ch <= ';F';)
        return ch - 65 + 10;
}

int main () {
    ull step = 100;
    std::string ms;
    std::cin >> n >> ms;
    ull m = 0;
    for (ull i = 0; i < ms.size(); ++i) {
        m = m * n + ti(ms[i]);
    }
    for (step = 0; !check(m) && step <= 30; ++step) {
        m = next;
        /*if (step > 30) {
            std::cout << "Impossible!" << std::endl; 
            return 0;
        }*/
    }
	if (step > 30) {
		std::cout << "Impossible!" << std::endl;
		return 0;
	}
    std::cout << "STEP=" << step << std::endl;
}