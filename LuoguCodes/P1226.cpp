//【P1226】取余运算_快速幂 - 洛谷 - 16 
#include<cstdio>
#include<iostream>

using  namespace  std;

#define ll long long

ll mod(ll a, ll b, ll c) 
{
	ll ans = 1;
	while (b) 
	{
		if (b % 2 == 1)
			ans = ans * a % c;
		a = a * a % c;
		b /= 2;
	}
	return ans;
}

int main() 
{
	ll b, p, k;
	cin >> b >> p >> k;
	cout << b << ';^'; << p << " mod " << k << ';=';;
	cout << mod(b, p, k) % k << endl;
}