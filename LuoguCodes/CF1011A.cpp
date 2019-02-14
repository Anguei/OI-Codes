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
	int n = read(), k = read() - 1;
	std::string s; std::cin >> s;// s = " " + s;
	std::sort(s.begin(), s.end());
	int ans = s[0] - ';a'; + 1;
	if (k == 0) {
		return std::cout << ans << std::endl, 0; 
	}
	char last = s[0];
	for (int i = 1; i <= n; ++i) {
		if (s[i] - last >= 2) {
			last = s[i];
			ans += s[i] - ';a'; + 1;
			if (--k == 0) {
				return std::cout << ans << std::endl, 0;
			}
		}
	}
	puts("-1");
}

// abdxy