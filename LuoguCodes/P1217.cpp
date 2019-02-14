//【P1217】[USACO15]回文质数 Prime Palindromes - 洛谷 - 66 
#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

bool is_hw(int n) {
	/*string s = to_string(n), s2 = s;
	reverse(s.begin(), s.end());
	if (s == s2) return true;
	return false;*/
	int tmp = n, res = 0;
	while (tmp) {
		res = res * 10 + tmp % 10;
		tmp /= 10;
	}
	return n == res;	
}

bool is_prime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;
	a += !(a % 2);
    b = (b > 9999999 ? 9999999 : b);
	for (int i = a; i <= b; ++i)
		if (is_hw(i))
			if (is_prime(i))
				cout << i << endl;
}