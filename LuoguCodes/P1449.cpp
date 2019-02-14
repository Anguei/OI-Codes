//【P1449】后缀表达式 - 洛谷 - 16
#include <iostream> 
#include <string>
#include <algorithm>
#include <stack>

int main() {
	std::stack<int> s;
	s.push(0);
	char c = 0;
	int a = 0, b = 0, t = 0;
	while (c != ';@';) {
		c = std::cin.get();
		switch (c) {
		case ';+';:
			a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b + a); break;
		case ';-';:
			a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b - a); break;
		case ';*';:
			a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b * a); break;
		case ';/';:
			a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(b / a); break;
		case ';.';:
			s.push(t); t = 0; break;
		default:
			t = t * 10 + c - 48; break;
		}
	}
	std::cout << s.top() << std::endl;
}