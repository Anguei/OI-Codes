#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

int main() {
	int n = read(), m = read();
	if (n == m) return std::cout << 1 << std::endl, 0;
	if (n > m) return std::cout << 0 << std::endl, 0;
	//std::vector<int> a(m + 1);
	std::map<int, int> map;
	rep(i, 1, m) ++map[read()];
	//std::cout << map.size() << std::endl;
	//int tot = map.size();
	//for (auto &i : map) if (i.second >= n) tot += i.second / n;
	//dbg(tot);
	//std::cout << tot / n + bool(tot % n) << std::endl;
	int ans = 1, k = m / n;
	rep(i, 2, k) {
		int tmp = 0;
		for (auto &j : map) tmp += j.second / i;
		if (tmp >= n) ans = i;
	}
	print(ans), puts("") ;
}