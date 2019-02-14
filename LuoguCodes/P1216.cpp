#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int A[MAXN][MAXN], F[MAXN][MAXN], N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> A[i][j];
	F[1][1] = A[1][1];
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			F[i][j] = max(F[i - 1][j - 1], F[i - 1][j]) + A[i][j];
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = max(ans, F[N][i]);
	cout << ans << endl;
}