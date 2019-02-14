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
	std::string s, t; int n = read(); std::cin >> s >> t; s = " " + s; t = " " + t;
	if (s == t) return puts("0"), 0;
	std::map<char, int> ss, st; for (auto i : s) ++ss[i]; for (auto i : t) ++st[i];
	rep(i, ';a';, ';z';) if (ss[i] != st[i]) return puts("-1"), 0;
	int map[55] = { 0 };
	std::vector<bool> used(n);
	rep(i, 1, n) rep(j, 1, n) if (!used[j] && s[i] == t[j]) {
		used[j] = true;
		map[i] = j;
		break;
	}
	std::vector<int> ans;
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (i == map[j]) {
				//std::clog << "Ifing...";
				for (int k = j - 1; k >= i; --k) {
					ans.push_back(k);
					std::swap(map[k], map[k + 1]);
				}
			}
		}
	}
	print(ans.size()), puts("");
	for (auto i : ans) print(i), putchar('; ';); puts("");
}