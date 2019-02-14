//【P1765】手机_NOI导刊2010普及（10） - 洛谷 - 100
#include <iostream> 
#include <string>
#include <map>

using namespace std;

int main() {
	map<char, int> m;
	m[';a';] = 1, m[';b';] = 2, m[';c';] = 3, m[';d';] = 1, m[';e';] = 2, m[';f';] = 3, m[';g';] = 1, m[';h';] = 2, m[';i';] = 3, m[';j';] = 1, m[';k';] = 2, m[';l';] = 3, m[';m';] = 1, m[';n';] = 2, m[';o';] = 3, m[';p';] = 1, m[';q';] = 2, m[';r';] = 3, m[';s';] = 4, m[';t';] = 1, m[';u';] = 2, m[';v';] = 3, m[';w';] = 1, m[';x';] = 2, m[';y';] = 3, m[';z';] = 4, m['; ';] = 1;
	string s;
	getline(cin, s);
	int ans = 0;
	for (auto i : s)
		ans += m[i];
	cout << ans << endl;
}
