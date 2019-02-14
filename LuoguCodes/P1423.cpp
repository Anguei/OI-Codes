//【P1423】小玉在游泳 - 洛谷 - 0
#include <iostream> 

using namespace std;

int main()
{
	double tot;
	cin >> tot;
	double m = 2, now;
	int step = 0;
	while (now < tot)
	{
		now += m;
		m *= 0.98;
		++step;
	}
	cout << step << endl;
}