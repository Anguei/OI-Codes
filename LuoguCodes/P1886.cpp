//【P1886】滑动窗口 - 洛谷 - 0 
#include <iostream>
#include <deque>
#include <algorithm>

const unsigned kMaxN = 1000000;
int a[kMaxN + 5] = { 0 }, q1[kMaxN + 5] = { 0 }, q2[kMaxN + 5] = { 0 };

inline void work1(const register unsigned &n, const register int &k) {
	register unsigned head = 1, tail = 0;
	for (register unsigned i = 1; i <= n; ++i) {
		while (head <= tail && q1[head] + k <= i) 
			++head;
		while (head <= tail && a[i] < a[q1[tail]])
			--tail;
		q1[++tail] = i;
		if (i >= k) std::cout << a[q1[head]] << " ";
	}
	std::cout << std::endl;
}

inline void work2(const register unsigned &n, const register int &k) {
	register unsigned head = 1, tail = 0;
	for (register unsigned i = 1; i <= n; ++i) {
		while (head <= tail && q2[head] + k <= i)
			++head;
		while (head <= tail && a[i] > a[q2[tail]])
			--tail;
		q2[++tail] = i;
		if (i >= k) std::cout << a[q2[head]] << " ";
	}
	std::cout << std::endl;
}

int main() {
	register unsigned n;
	register int k;
	std::cin >> n >> k;
	for (register unsigned i = 1; i <= n; ++i) 
		std::cin >> a[i];
	work1(n, k);
	work2(n, k);
}