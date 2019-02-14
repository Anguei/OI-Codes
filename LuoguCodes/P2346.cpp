#include <queue>
#include <iostream>
#include <algorithm>
#define dbg(x) std::clog << #x " = " << x << std::endl;
#define rep(i, a, b) for (int i = (a);  i <= (b); ++i)

struct Status {
	int step, color, a[5][5];
} s;

const int n = 4;
const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main() {
	rep(i, 1, n) rep(j, 1, n) {
		char tmp; std::cin >> tmp;
		if (tmp == ';W';) s.a[i][j] = 0;
		else if (tmp == ';B';) s.a[i][j] = 1;
		else if (tmp == ';O';) s.a[i][j] = 2;
	}
	s.step = 0; s.color = 2;
	std::queue<Status> q;
	rep(i, 1, n) rep(j, 1, n) if (s.a[i][j] == 2) rep(k, 0, 3) {
		int dx = i + dir[k][0], dy = j + dir[k][1];
		if (dx < 1 || dy < 1 || dx > n || dy > n || s.a[dx][dy] == 2) continue;
		Status now = s; now.color = now.a[dx][dy]; now.step = 1;
		std::swap(now.a[i][j], now.a[dx][dy]);
		q.push(now);
	}
	auto success = [](const Status &now) {
		//std::clog << "Checking... " << now.step << std::endl;
		if (now.a[1][1] == now.a[1][2] && now.a[1][2] == now.a[1][3] && now.a[1][3] == now.a[1][4]) return true;
		if (now.a[2][1] == now.a[2][2] && now.a[2][2] == now.a[2][3] && now.a[2][3] == now.a[2][4]) return true;
		if (now.a[3][1] == now.a[3][2] && now.a[3][2] == now.a[3][3] && now.a[3][3] == now.a[3][4]) return true;
		if (now.a[4][1] == now.a[4][2] && now.a[4][2] == now.a[4][3] && now.a[4][3] == now.a[4][4]) return true;
		if (now.a[1][1] == now.a[2][1] && now.a[2][1] == now.a[3][1] && now.a[3][1] == now.a[4][1]) return true;
		if (now.a[1][2] == now.a[2][2] && now.a[2][2] == now.a[3][2] && now.a[3][2] == now.a[4][2]) return true;
		if (now.a[1][3] == now.a[2][3] && now.a[2][3] == now.a[3][3] && now.a[3][3] == now.a[4][3]) return true;
		if (now.a[1][4] == now.a[2][4] && now.a[2][4] == now.a[3][4] && now.a[3][4] == now.a[4][4]) return true;
		if (now.a[1][1] == now.a[2][2] && now.a[2][2] == now.a[3][3] && now.a[3][3] == now.a[4][4]) return true;
		if (now.a[1][4] == now.a[2][3] && now.a[2][3] == now.a[3][2] && now.a[3][2] == now.a[4][1]) return true;
		
		rep(i, 1, n) {
			int target = now.a[i][1]; bool flag = true;
			rep(j, 1, n) if (now.a[i][j] ^ target) flag = false; if (flag) return true;
		}
		bool flag = true; int target = now.a[1][1];
		rep(i, 1, n) if (now.a[i][i] ^ target) flag = false; if (flag) return true;
		flag = true; target = now.a[1][4];
		rep(i, 1, n) if (now.a[i][5 - i] ^ target) flag = false; if (flag) return true;
		return false;
	};
	std::clog.tie(nullptr);
	std::cerr.tie(nullptr);
	while (!q.empty()) {
		Status x = q.front(); q.pop();
		if (success(x)) { std::cout << x.step << std::endl; return 0; }
		rep(i, 1, n) rep(j, 1, n) if (x.a[i][j] == 2) rep(k, 0, 3) {
			int dx = i + dir[k][0], dy = j + dir[k][1];
			if (dx < 1 || dy < 1 || dx > n || dy > n || x.a[dx][dy] ^ (x.color ^ 1)) continue;
			Status now = x; now.step = x.step + 1; now.color = x.color ^ 1;
			std::swap(now.a[i][j], now.a[dx][dy]);
			q.push(now);
		}
	}
}
		