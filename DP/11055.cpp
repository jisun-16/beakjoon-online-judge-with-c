#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[1001], dp[1001], ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		if (ans < dp[i]) ans = dp[i];
	}

	cout << ans << '\n';
}