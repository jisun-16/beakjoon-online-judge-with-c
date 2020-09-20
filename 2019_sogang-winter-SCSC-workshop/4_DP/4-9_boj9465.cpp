#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int T, n;
int sticker[2][100001], dp[2][100001];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int k = 0; k < 2; k++) {
			for (int l = 0; l < n; l++) cin >> sticker[k][l];
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[0][1] + dp[1][0];
		dp[1][1] = sticker[1][1] + dp[0][0];
		for (int k = 2; k < n; k++) {
			dp[0][k] = sticker[0][k] + max(dp[1][k - 1], dp[1][k - 2]);
			dp[1][k] = sticker[1][k] + max(dp[0][k - 1], dp[0][k - 2]);
		}

		int ans = max(dp[0][n - 1], dp[1][n - 1]);
		cout << ans << endl;
	}
}