//【P1615】西游记公司 - 洛谷 - 0 
#include <cstdio>
#include <iostream> 

int main() {
	struct Time {
		int h, m, s;
		Time(int _h = 0, int _m = 0, int _s = 0) : h(_h), m(_m), s(_s) {}
	};
	Time time1, time2;
	int th, tm, ts;
	scanf("%d:%d:%d", &th, &tm, &ts);
	time1 = Time(th, tm, ts);
	scanf("%d:%d:%d", &th, &tm, &ts);
	time2 = Time(th, tm, ts);
	int n;
	std::cin >> n;
	long long h, m, s, time;
	h = time2.h - time1.h;
	m = time2.m - time1.m;
	s = time2.s - time1.s;
	time = h * 3600 + m * 60 + s;
	std::cout << time * n << std::endl;
}