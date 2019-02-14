//【SP4】ONP - Transform the Expression - 洛谷 - Uk 
#include <cctype> 

#include <stack>
#include <string>
#include <iostream>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::string expression;
		std::cin >> expression;
		std::stack<char> stack;
		for (char ch : expression) {
			if (isalpha(ch))
				std::cout << ch;
			else if (ch == ';)';) {
				std::cout << stack.top();
				stack.pop();
			}
			else if (ch != ';(';)
				stack.push(ch);
		}
		while (!stack.empty()) {
			std::cout << stack.top();
			stack.pop();
		}
		std::cout << std::endl;
	}
}