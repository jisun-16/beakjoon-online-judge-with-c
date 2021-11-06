#include<iostream>
#include<algorithm>
#define inf 987654321

using namespace std;

int t, k, file[501], dp[501][501], sum[501];

void init() {
	for (int i = 0; i < 501; i++) {
		file[i] = 0;
		sum[i] = 0;
		for (int j = 0; j < 501; j++)
			dp[i][j] = inf;
	}
}

int DP(int start, int end) {
	if (start >= end) return 0;
	if (start + 1 == end) return file[start] + file[end];

	if (dp[start][end] != inf) return dp[start][end];

	for (int i = start; i < end; i++) {
		int temp = DP(start, i) + DP(i + 1, end) + (sum[end] - sum[start - 1]);
		dp[start][end] = min(dp[start][end], temp);
	}

	return dp[start][end];
}

int main() {
	cin >> t;
	while (t--) {
		init();
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		cout << DP(1, k) << '\n';
	}
}