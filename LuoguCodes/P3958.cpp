#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 1011;
struct Ball {
	ll x, y, z;
	Ball() {};
	Ball(ll _x, ll _y, ll _z): x(_x), y(_y), z(_z) {}
} a[MAXN];
ll n, h, r;
int q[MAXN], qhead, qtail;
bool vis[MAXN];

inline ll s(ll x) {
	return x * x;
}

inline bool intc(const Ball &a, const Ball &b) {
	return 4 * s(r) - s(a.x - b.x) - s(a.y - b.y) - s(a.z - b.z) >= 0;
}

inline bool bfs() {
	qhead = qtail = 0;
	memset(vis, false, sizeof vis);
	for (int i = 0; i < n; ++i) {
		if (a[i].z <= r) q[qtail++] = i;
	}
	while (qhead != qtail) {
		int now = q[qhead++];
		if (h - a[now].z <= r) return true;
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && intc(a[now], a[i])) {
				vis[i] = true;
				q[qtail++] = i;
			}
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> h >> r;
		for (int i = 0; i < n; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			a[i] = Ball(x, y, z);
		}
		cout << (bfs() ? "Yes" : "No") << endl;
	}
	return 0;
}