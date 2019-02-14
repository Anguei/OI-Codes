//【P1996】约瑟夫问题 - 洛谷 - 0 
#include <iostream>
#include <algorithm> 

int main() {
	int n, m;
	std::cin >> n >> m;
	bool *vis = new bool[n + 1];
	//bool vis[105];
	for (int i = 0; i <= n; ++i) 
		vis[i] = false;
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (++pos > n) 
				pos = 1;
			if (vis[pos])
				--j;
		}
		std::cout << pos << " ";
		vis[pos] = true;
	}
	std::cout << std::endl;
}