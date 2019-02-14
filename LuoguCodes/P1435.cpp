//【P1435】回文字串 - 洛谷 - 0
#include <string>
#include <iostream>
#include <algorithm>

const int kMaxSize = 5000;
int dp[kMaxSize + 5][kMaxSize + 5] = { 0 };

int main() {
	std::string s1;
	std::cin >> s1;
	int n = s1.size();
	std::string s2(s1);
	std::reverse(s2.begin(), s2.end());
	s1 = " " + s1;
	s2 = " " + s2;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
	std::cout << n - dp[n][n] << std::endl;
}