#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

long long T, N, dp[101];

int main() {
	cin >> T;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp[N] << endl;
	}
}