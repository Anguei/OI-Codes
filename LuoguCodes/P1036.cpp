//【P1036】选数 - 洛谷.cpp - 16
#include <iostream>
#include <algorithm>

const int MAXN = 20;
int x[MAXN + 3] = {0};
int ans = 0;
int n, k;


inline bool is_prime(int n) {
    if (n == 0 || n == 1) 
        return false;
    if (n == 2)
         return true;
    for (int i = 2; i * i <= n; ++i) 
        if (n % i == 0) 
            return false;
    return true;
}

inline void dfs(int now, int cnt, int num) {
	if (cnt == k) {
		if (is_prime(num))
			++ans;
		return;
	}
	for (int i = now; i <= n; ++i) {
		dfs(i + 1, cnt + 1, num + x[i]);
	}
}

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> x[i];
    //for (int i = 1; i <= n; ++i) std::cout << x[i] << " ";
    //for (int i = 0; i < 100; ++i) if (is_prime(i)) std::cout << i << " " << is_prime(i) << std::endl;
    dfs(1, 0, 0);
    std::cout << ans << std::endl;
}