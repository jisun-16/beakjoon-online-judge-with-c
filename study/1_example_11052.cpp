#include<iostream>
#include<algorithm>

using namespace std;

int card[1001], dp[1001], n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> card[i];

	dp[0] = 0;
	dp[1] = card[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = card[i];
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i - j] + card[j], dp[i]);
		}
	}

	cout << dp[n] << endl;
}