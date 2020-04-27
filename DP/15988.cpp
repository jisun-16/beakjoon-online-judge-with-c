#include<iostream>
#include<algorithm>
#define MOD 1000000009

using namespace std;

int t, n;
long long dp[1000001];

int main() {
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	cin >> t;

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}