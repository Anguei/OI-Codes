//【P2615】神奇的幻方 - 洛谷 - 100
#include <iostream> 

int main() {
	int n;
	std::cin >> n;
	int a[n + 1][n + 1]; // 这不是标准写法，但是可以这么写
	for (int i = 0; i < n + 1; ++i)
		for (int j = 0; j < n + 1; ++j)
			a[i][j] = 0;
			
	int step = 1; 	// 填到几了
	int posx, posy; // 上一个点坐标
	while (step <= n * n) {
		if (step == 1) 
			a[posx = 1][posy = n / 2 + 1] = step++;
		else if (posx == 1 && posy != n) 
			a[posx = n][posy = posy + 1] = step++;
		else if (posx != 1 && posy == n) 
			a[posx = posx - 1][posy = 1] = step++;
		else if (posx == 1 && posy == n) 
			a[posx = posx + 1][posy = posy] = step++;
		else if (posx != 1 && posy != n)
			if (a[posx - 1][posy + 1] == 0)
				a[posx = posx - 1][posy = posy + 1] = step++;
			else
				a[posx = posx + 1][posy = posy] = step++;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}