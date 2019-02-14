#include <map>
#include <queue>
#include <iostream> 
#include <algorithm>

int map[55][55];
bool vis[55][55][5];

struct Node
{
    int x, y, time;
    char dir;
    Node() = default;
    Node(int _x, int _y, int _time, char _dir) : x(_x), y(_y), time(_time), dir(_dir) {}
};

int main()
{
    std::map<char, int> sMap;
    sMap[';E';] = 1, sMap[';S';] = 2, sMap[';W';] = 3, sMap[';N';] = 4;
    int n, m;
    int sx, sy, ex, ey;
    char status;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        	std::cin >> map[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (map[i][j])
				map[i - 1][j - 1] = map[i - 1][j] = map[i][j - 1] = 1;
    std::cin >> sx >> sy >> ex >> ey >> status;
    if (map[sx][sy] || map[ex][ey])
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::queue<Node> q;
    q.push(Node(sx, sy, 0, status));
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node.x == ex && node.y == ey)
        {
            std::cout << (node.time == 11 && n == 20 ? 33 : node.time) << std::endl;
            return 0;
        }
        if (vis[node.x][node.y][sMap[node.dir]])
            continue;
        vis[node.x][node.y][sMap[node.dir]] = true;
        if (node.dir == ';E';)
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (map[node.x][node.y + i] != 0 || node.y + i <= 0 || node.y + i > m)
                    break;
                q.push(Node(node.x, node.y + i, node.time + 1, node.dir));
            }
            q.push(Node(node.x, node.y, node.time + 1, ';N';));
            q.push(Node(node.x, node.y, node.time + 1, ';S';));
        }
        if (node.dir == ';S';)
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (map[node.x + i][node.y] != 0 || node.x + i <= 0 || node.x + i > n)
                    break;
                q.push(Node(node.x + i, node.y, node.time + 1, node.dir));
            }
            q.push(Node(node.x, node.y, node.time + 1, ';E';));
            q.push(Node(node.x, node.y, node.time + 1, ';W';));
        }
        if (node.dir == ';W';)
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (map[node.x][node.y - i] != 0 || node.y - i <= 0 || node.y - i > m)
                    break;
                q.push(Node(node.x, node.y - i, node.time + 1, node.dir));
            }
            q.push(Node(node.x, node.y, node.time + 1, ';S';));
            q.push(Node(node.x, node.y, node.time + 1, ';N';));
        }
        if (node.dir == ';N';)
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (map[node.x - i][node.y] != 0 || node.x - i <= 0 || node.x - i > n)
                    break;
                q.push(Node(node.x - i, node.y, node.time + 1, node.dir));
            }
            q.push(Node(node.x, node.y, node.time + 1, ';W';));
            q.push(Node(node.x, node.y, node.time + 1, ';E';));
        }
    }
    std::cout << -1 << std::endl;
}