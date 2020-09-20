#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int T, n, dp[11];

int main() {
	cin >> T;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << endl;
	}
}