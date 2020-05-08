#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int n, m;
long long dp[21][21], fac[21];

void init() {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		for (int j = 1; j <= m; j++)
			dp[i][j] = -1;
	}
}

long long _gcd(long long a, long long b) {
	if (b == 0) return a;
	return _gcd(b, a % b);
}

int main() {
	cin >> n >> m;
	init();

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			//if (dp[i][j] != -1) continue;
			if (i == 0 || i <= j) {
				dp[i][j] = fac[i];
				continue;
			}
			if (j == 0) {
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = 0;
			for (int k = 1; k <= i; k++) {
				dp[i][j] += (fac[i - 1] / fac[i - k]) * dp[i - k][j - 1];
			}
		}
	}

	long long a = dp[n][m], b = fac[n];
	long long gcd = _gcd(a, b);
	a /= gcd;
	b /= gcd;

	cout << a<<'/'<<b << '\n';
}