#include <cstdio>
#include <queue>

const int MAXN = 100, INF = 2147483647;
int f[MAXN + 5][MAXN + 5];
int pic[MAXN + 5][MAXN + 5];
int pic2[MAXN + 5][MAXN + 5];
int dir[4][2] = { { 1, 0 },{ 0, 1 },{ 0, -1 },{ -1, 0 } };

inline void bfs(int m) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(1, 1));
	int cost = 0;
	f[1][1] = 0;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int dx = x + dir[i][0], dy = y + dir[i][1];
			if (dx < 1 || dy < 1 || dx > m || dy > m)
				continue;

			cost = f[x][y];
			if (pic[x][y] == 2)
			{
				if (pic[dx][dy] == 2)
					continue;
				if (pic2[x][y] != pic[dx][dy])
					++cost;
			}
			else if (pic[x][y] != pic[dx][dy])
				if (pic[dx][dy] == 2)
					cost += 2;
				else
					++cost;

			if (cost < f[dx][dy])
			{
				f[dx][dy] = cost;
				if (pic[dx][dy] == 2)
					pic2[dx][dy] = pic[x][y];
				q.push(std::make_pair(dx, dy));
			}
		}
	}
}

inline int read() {
	int ret = 0;
	bool sign = false;
	char ch = getchar();
	while (ch > ';9'; || ch < ';0';) {
		if (ch == ';-';) sign = true;
		ch = getchar();
	}
	while (ch >= ';0'; && ch <= ';9';) {
		ret = ret * 10 + ch - ';0';;
		ch = getchar();
	}
	if (sign) ret *= -1;
	return ret;
}

inline void openFile() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
}

int main()
{
	//openFile();

	int m, n;
	m = read(), n = read();
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; j++) {
			f[i][j] = INF;
			pic[i][j] = 2;
		}

	for (int i = 0; i < n; ++i) {
		int x, y, c;
		x = read(), y = read(), c = read();
		pic[x][y] = pic2[x][y] = c;
	}

	bfs(m);

	printf("%d\n", (f[m][m] == INF ? -1 : f[m][m]));
}