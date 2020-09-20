#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int n;
int rgb[3][1000], dp[3][1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
	}

	dp[0][0] = rgb[0][0];
	dp[1][0] = rgb[1][0];
	dp[2][0] = rgb[2][0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = rgb[0][i] + min(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] = rgb[1][i] + min(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] = rgb[2][i] + min(dp[0][i - 1], dp[1][i - 1]);
	}

	int ans = min({ dp[0][n - 1],dp[1][n - 1],dp[2][n - 1] });
	cout << ans << endl;
}