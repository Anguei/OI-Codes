//【P1968】美元汇率 - 洛谷 - 10
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>

struct Income {
	double dollar, mark;
	Income() {}
} *f;
int n, *a;

void input() {
	std::cin >> n;
	a = new int[n + 1];
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
}

int main()  {
	input();
	f = new Income[n + 1];
	f[1].dollar = 100.0, f[1].mark = a[1];
	for (int i = 2; i <= n; ++i) {
		f[i].dollar = std::max(f[i - 1].dollar, f[i - 1].mark / a[i] * 100.0);
		f[i].mark = std::max(f[i - 1].mark, f[i - 1].dollar * a[i] / 100.0);
	}
	printf("%.2f", (f[n].dollar > f[n].mark ? f[n].dollar : f[n].mark / a[n] * 100.0));
	/*
	double now_my = 100.0, now_mk = 0.0, max_hl = 0.0, min_hl = 2147483647.0;
	for (int i = 0; i < n; ++i) {
		if (i + 1 == n) {
			now_my += now_mk * 100.0 / a[i];
			now_mk = 0.0;
		}
		else if (a[i] > max_hl) {
			now_mk += a[i] / 100.0 * now_my;
			now_my = 0.0;
		}
		else if (a[i] < min_hl) {
			now_my += now_mk * 100.0 / a[i];
			now_mk = 0.0;
		}
		max_hl = std::max(max_hl, double(a[i]));
		min_hl = std::min(min_hl, double(a[i]));
	}
	printf("%.2f", now_my);
	*/
	
}