#include<iostream>
#include<algorithm>

using namespace std;

int n, dp[31];

int main() {
	cin >> n;

	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = 2;//자기자신의 special case

		dp[i] += (dp[i - 2] * 3);
		for (int j = 4; j < i; j += 2) {
			dp[i] += (dp[i - j] * 2);
		}
	}

	cout << dp[n] << '\n';
}