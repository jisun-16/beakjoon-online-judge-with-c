#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#define MOD 1000000000

using namespace std;

int n, k;
long long dp[201][201];//dp[n][k]

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) dp[i][1] = 1;
	for (int i = 1; i <= k; i++) {
		dp[0][i] = 1;
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <=k; j++) {
			for (int l = i; l >= 0; l--) {
				dp[i][j] += dp[i - l][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}

	long long ans = dp[n][k] % MOD;

	cout << ans << '\n';
}