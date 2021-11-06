#include<iostream>
#include<algorithm>
#define MIN -1001

using namespace std;

int n, arr[100001], mn = 0;
int dp[100001][2], ans = MIN; // dp[][버린 수의 개수]

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cout << arr[1] << '\n';
		return 0;
	}

	dp[1][0] = arr[1];
	dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}

	cout << ans << '\n';
	
	return 0;
}