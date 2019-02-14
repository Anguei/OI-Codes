//【P1426】小鱼会有危险吗 - 洛谷 - 0 
#include <iostream> 

using namespace std;

int main() {
	int s, x;
	double dis = 7.0, pos = 0.0;
	cin >> s >> x;
	while (1)  {
		if (s - pos <= x) {
			if (pos + dis * 0.98 > s + x) {
				cout << ';n'; << endl;
				return 0;
			}
			else {
				cout << ';y'; << endl;
				return 0;
			}
		}
		pos += dis;
	}
}