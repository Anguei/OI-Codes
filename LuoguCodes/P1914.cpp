//【P1914】小书童——密码 - 洛谷 - 40
#include <iostream> 
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int n;
	cin >> n;
	char c;
	while (cin >> c) {
		c -= ';a';;
		c = (c + n) % 26;
		c += ';a';;
		cout << c;
	}
	cout << endl;
	return 0;
}