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

const int N = 100000 + 5;

int in[N], out[N], topo[N];
std::vector<int> g[N];
std::priority_queue<int> pq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("4010.in", "r", stdin);
	freopen("4010.out", "w", stdout);
#endif
	int T = read();
	while (T--) {
		memset(in, 0, sizeof in); 
		memset(out, 0, sizeof out);
		memset(topo, 0, sizeof topo);
		for (int i = 0; i < N; ++i) g[i].clear();
		
		int n = read(), m = read();
		rep(i, 1, m) {
			int x = read(), y = read(); 
			g[y].push_back(x);
			++in[x];
		}
		rep(i, 1, n) if (!in[i]) pq.push(i);
		
		int tot = n;
		while (!pq.empty()) {
			int u = pq.top(); pq.pop();
			topo[tot--] = u;
			for (int i = 0; i < g[u].size(); ++i) {
				const int &to = g[u][i];
				--in[to];
				if (!in[to]) pq.push(to);
			}
		}
		
		if (tot) printf("Impossible!");
		else rep(i, 1, n) print(topo[i]), putchar('; ';); 
		puts("");
	}
}