#include <iostream> 
//#include <stack>
#include <string>

int main() {
	//std::stack<char> stk;
	std::string s;
	std::getline(std::cin, s);
	/*for (auto i : s)
		stk.push(i);
	int zkh, ykh;
	zkh = ykh = 0;
	bool ok = true;
	while (stk.size()) {
		char ch = stk.top();
		stk.pop();
		if (ch == ';@'; || ch == ';\n'; || ch == ';\0';) break;
		ch == ';('; ? ++zkh : ++ykh;
		ykh > zkh ? ok = false : ok;
	}
	if (zkh != ykh)
		ok = false;*/
	int zkh = 0, ykh = 0;
	bool ok = true;
	for (auto i : s) {
		if (i == ';(';) ++zkh;
		if (i == ';)';) ++ykh;
		if (ykh > zkh) ok = false;
	}
	if (ykh != zkh) ok = false;
	std::cout << (ok ? "YES" : "NO") << std::endl;
}