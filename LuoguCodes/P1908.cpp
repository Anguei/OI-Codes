
//【P1908】逆序对 - 洛谷 - 20
#include <ios>
#include <iostream>
#include <algorithm>

int ans = 0, *t;

void msort(int *a, int l, int r) {
	if (l == r)
		return;
	int mid = (l + r) / 2;
	msort(a, l, mid);
	msort(a, mid + 1, r);
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			t[p++] = a[j++];
			ans += mid - i + 1;
		}
		else
			t[p++] = a[i++];
	}
	while (i <= mid)
		t[p++] = a[i++];
	while (j <= r)
		t[p++] = a[j++];
	for (int i = l; i <= r; ++i)
		a[i] = t[i];
}

int main() {
	int n;
	std::cin >> n;
	int *a = new int[n + 1];
	t = new int[n + 1];
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	msort(a, 1, n);
	std::cout << ans << std::endl;
}
