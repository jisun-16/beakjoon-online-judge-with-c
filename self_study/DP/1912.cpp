#include<iostream>
#include<algorithm>
#define MIN -100000001

using namespace std;

int n, arr[100001], dp[100001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	int ans = MIN;
	for (int i = 1; i <= n; i++)
		if (ans < dp[i]) ans = dp[i];

	cout << ans << '\n';
}