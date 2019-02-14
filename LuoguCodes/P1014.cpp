//【P1014】Cantor表 - 洛谷 - 0
#include <iostream>

using namespace std;

int main() {
	const int MAXN = 3162;
	int n;
	cin >> n;
	int line = 1;
	while (n - 1 >=line) {
		n -= line;
		++line;
	}
	if (line % 2 == 1) {
		cout << line - n + 1 << ';/'; << n << endl;
	}
	else {
		cout << n << ';/'; << line - n + 1 << endl;
	}
}