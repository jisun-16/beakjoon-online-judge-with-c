#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[1001], dp[1001][1001];//dp[start][end]

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		for (int start = 1; start <= n - i; start++) {
			int end = start + i;
			if (arr[start] == arr[end])
				dp[start][end] = dp[start + 1][end - 1] + 1;
			else
				dp[start][end] = dp[start + 1][end - 1];

			for (int j = start + 1; j < end; j++)
				dp[start][end] = max(dp[start][end], dp[start][j] + dp[j + 1][end]);
		}
	}

	cout << dp[1][n] << '\n';
}