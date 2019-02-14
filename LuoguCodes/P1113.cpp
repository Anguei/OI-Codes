#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

const int N = 10000 + 5;

struct Node {
	int id, len, tot;
	std::vector<int> need;
};

struct Edge {
	int v, w;
	Edge(int _v, int _w) : v(_v), w(_w) {}
};

int in[N], out[N];
Node a[N];
std::queue<int> q;
std::vector<Edge> g[N];

int main() {
	int n = read();
	rep(i, 1, n) {
		a[i].id = read(); a[i].len = read(); int tmp = read();
		while (tmp) {
			g[tmp].push_back(Edge(a[i].id, a[i].len));
			// 统计入度和出度
			++in[a[i].id];  
			++out[tmp];
			tmp = read();
		}
	}
	rep(i, 1, n) {
		if (!in[i]) {
			q.push(i); // 入度为零的入队 
			a[i].tot = a[i].len;
		}
	}
	int ans = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); ++i) {
			const Edge &e = g[u][i];
			int to = e.v;
			--in[to];
			a[to].tot = std::max(a[to].tot, a[u].tot + a[to].len);
			if (!in[to]) {
				if (!out[to]) ans = std::max(ans, a[to].tot);
				else q.push(to);
			}
		}
	}
	print(ans), puts("");
}