//【P1440】求m区间内的最小值 - 洛谷 - 0
/*#include <cstdio>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <ios>

int a[2000000 + 10];

inline int read() {
	register bool flag = false;
	register char c = std::cin.get();
	register int ans = 0;
	while (c > ';9'; || c < ';0';) {
		if (c == ';-';)
			flag = true;
		c = std::cin.get();
	}
	while (c <= ';9'; && c >= ';0';) {
		ans += c - 48;
		c = std::cin.get();
	}
	return ans;
}

int main() {
	//std::vector<int> v;
	std::deque<int> q;
	std::ios::sync_with_stdio(false);
	register int n, k;
	//std::cin >> n >> k;
	n = read(), k = read();
	printf("0\n");
	q.push_back(0);
	for (register int i = 1; i <= n; ++i) {
		//std::cout << a[q.front()] << std::endl;
		printf("%d\n", a[q.front()]);
		//std::cin >> a[i];
		a[i] = read();
		if (!q.empty() && i - q.front() + 1 > k)
			q.pop_front();
		while (!q.empty() && a[q.back()] > a[i])
			q.pop_back();
		q.push_back(i);
	}
}*/




































#include <cstdio>
#include <iostream>

inline int read() {
	register bool flag = false;
	register char c = std::cin.get();
	register int ans = 0;
	while (c > ';9'; || c < ';0';) {
		if (c == ';-';)
			flag = true;
		c = std::cin.get();
	}
	while (c <= ';9'; && c >= ';0';) {
		ans += c - 48;
		c = std::cin.get();
	}
	return ans;
}

int a[2000000 + 10][2];

int main() {
	int n, m;
	//std::cin >> n >> m;
	//n = read(), m = read();
	scanf("%d %d", &n, &m);
	//std::cout << 0 << std::endl; 
	printf("0\n");
	int head, tail = 0;
	head = tail = 0;
	scanf("%d", &a[tail++][0]);
	for (register int i = 1; i < n; ++i) {
		if (i - a[head][1] > m)
			++head;
		printf("%d\n", a[head][0]);
		int t;
		scanf("%d", &t);
		while (head < tail && t < a[tail - 1][0])
			--tail;
		a[tail][0] = t;
		a[tail][1] = i;
		++tail;
	}
}