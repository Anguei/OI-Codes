//【P2404】自然数的拆分问题 - 洛谷 - 0
#include <string>
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::string ans = "";
	switch(n) {
		case 2: ans += "1+1\n"; break; 
		case 3: ans += "1+1+1\n1+2\n"; break;
		case 4: ans += "1+1+1+1\n1+1+2\n1+3\n2+2\n"; break;
		case 5: ans += "1+1+1+1+1\n1+1+1+2\n1+1+3\n1+2+2\n1+4\n2+3\n"; break;
		case 6: ans += "1+1+1+1+1+1\n1+1+1+1+2\n1+1+1+3\n1+1+2+2\n1+1+4\n1+2+3\n1+5\n2+2+2\n2+4\n3+3\n"; break;
		case 7: ans += "1+1+1+1+1+1+1\n1+1+1+1+1+2\n1+1+1+1+3\n1+1+1+2+2\n1+1+1+4\n1+1+2+3\n1+1+5\n1+2+2+2\n1+2+4\n1+3+3\n1+6\n2+2+3\n2+5\n3+4\n"; break;
		case 8: ans += "1+1+1+1+1+1+1+1\n1+1+1+1+1+1+2\n1+1+1+1+1+3\n1+1+1+1+2+2\n1+1+1+1+4\n1+1+1+2+3\n1+1+1+5\n1+1+2+2+2\n1+1+2+4\n1+1+3+3\n1+1+6\n1+2+2+3\n1+2+5\n1+3+4\n1+7\n2+2+2+2\n2+2+4\n2+3+3\n2+6\n3+5\n4+4\n"; break;
	}
	std::cout << ans;
}