#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, A[1001], dp[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] <= A[j]) continue;
			dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) ans = dp[i];
	}

	cout << ans << endl;
}