// luogu-judger-enable-o2
#include <cstdio>
#include <cctype>
#include <cstring>
#include <stack> 
#include <string>
#include <iostream>
#include <algorithm>
#ifdef yyfLocal
#define dbg(x) std::clog << #x " = " << x << std::endl
#else
#define dbg(x) x
#endif

struct Code {
	int cur; char name; bool cannot;
	Code(int _cur, char _name, bool _cannot) : cur(_cur), name(_name), cannot(_cannot) {}
	Code() = default;
};

bool used[26];

int getDigits(const std::string &s) {
	if (isdigit(s[0])) return std::stoi(s);
	else return 0x7fffffff;
}

int main() {
#ifdef yyfLocal
	freopen("testdata.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	while (T--) {
		memset(used, false, sizeof used);
		//dbg(T);
		int L; std::string s; std::cin >> L >> s;
		int want = 0; if (s.size() != 4) sscanf(s.c_str(), "O(n^%d)", &want);
		int curAns = 0, maxAns = 0;
		bool ok = true, cannot = false;
		std::stack<Code> stack;
		while (L--) {
			std::string command;
			std::cin >> command;
			if (command == "F") {
				std::string a, b, c; 
				std::cin >> a >> b >> c;
				if (!ok) continue;
				if (used[a[0] - ';a';]) { ok = false; continue; }
				stack.push(Code(curAns, a[0], cannot));
				if (!cannot) if (b != "n" && c == "n") maxAns = std::max(maxAns, ++curAns); else if (getDigits(b) > getDigits(c)) cannot = true;
				used[a[0] - ';a';] = true;
			} else if (command == "E") {
				if (!ok || stack.empty()) { ok = false; continue; }
				const Code x = stack.top(); stack.pop(); curAns = x.cur; cannot = x.cannot; 
				used[x.name - ';a';] = false;
			}
			//dbg(maxAns), dbg(curAns);
		}
		std::cout << (!ok || stack.size() ? "ERR" : (maxAns == want ? "Yes" : "No")) << std::endl;
	}
}