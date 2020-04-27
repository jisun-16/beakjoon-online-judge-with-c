#include<iostream>
#include<algorithm>
#define MAX 1000000000

using namespace std;

int n, cost[1001][3], dp[1001][3][3];//dp[현재위치][현재색상][시작색상]

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < 3; j++) 
			for (int k = 0; k < 3; k++) dp[i][j][k] = MAX;

	dp[1][0][0] = cost[1][0]; dp[1][1][1] = cost[1][1]; dp[1][2][2] = cost[1][2];
	for (int i = 2; i < n; i++)
		for (int j = 0; j < 3; j++)
			for (int s = 0; s < 3; s++)
				dp[i][j][s] = min(dp[i - 1][(j + 1) % 3][s], dp[i - 1][(j + 2) % 3][s]) + cost[i][j];

	for (int j = 0; j < 3; j++)
		for (int s = 0; s < 3; s++)
			if (j != s) dp[n][j][s] = min(dp[n - 1][(j + 1) % 3][s], dp[n - 1][(j + 2) % 3][s]) + cost[n][j];

	int ans = MAX;
	for (int j = 0; j < 3; j++)
		for (int s = 0; s < 3; s++)
			ans = min(ans, dp[n][j][s]);

	cout << ans << '\n';
}