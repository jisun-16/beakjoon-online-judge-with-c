#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, tri[501][501], dp[501][501];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + tri[i][0];
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > ans) ans = dp[n - 1][i];
	}

	cout << ans << endl;
}