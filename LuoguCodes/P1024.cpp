#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define dbg(x) std::clog << #x << " = " << x << std::endl

const double eps = 0.00001;
int tot = 0;
double a, b, c, d;

double f(double x)
{
	double res = (a * x * x * x) + (b * x * x) + (c * x) + (d);
	//dbg(res);
	return res;
}

void print(double x)
{
	std::cout << std::fixed << std::setprecision(2) << x << " ";
}

void find(double l, double r)
{
#ifndef ONLINE_JUDGE
	std::clog << "Finding...\n";
#endif
	while (r - l > eps)
	{
		double mid = (l + r) / 2;
		if (f(mid) * f(r) < 0)
			l = mid;
		else
			r = mid;
	}
	print(l);
}

int main()
{
	std::cin >> a >> b >> c >> d;
	for (int i = -100; i < 100; ++i) 
	{
		/*dbg(f(i) * f(i + 1));
		if (f(i) * f(i + 1) < 0)
		{
			dbg(i), dbg(i + 1);
			find(i, i + 1);			
		}*/
		double l = i, r = i + 1;
		double y1 = f(l), y2 = f(r);
		if (!y1)
			print(l);
		if (y1 * y2 < 0)
		{
			find(l, r);
		}
	}
	puts("");
}