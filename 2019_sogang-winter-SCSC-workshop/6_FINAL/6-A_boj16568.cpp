#include<iostream>
#include<algorithm>
using namespace std;

int N, a, b;
int dp[1000001];

int main() {

	cin >> N >> a >> b;

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i - a - 1 >= 0) dp[i] = min(dp[i], dp[i - a - 1] + 1);
		if (i - b - 1 >= 0) dp[i] = min(dp[i], dp[i - b - 1] + 1);
	}

	cout << dp[N] << endl;
	
	return 0;
}