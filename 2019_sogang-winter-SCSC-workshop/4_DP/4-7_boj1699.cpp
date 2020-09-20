#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int n, dp[100001];

int main() {
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = i;
		for (int j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
		}
	}

	cout << dp[n] << endl;
}