#include<iostream>
#include<algorithm>
using namespace std;

int dp[2001][2001];
int n, arr[2001], m;

int DP(int start, int end) {
	if (dp[start][end] == 1) return 1;
	if (arr[start] != arr[end]) return 0;
	dp[start][end] = DP(start + 1, end - 1);
	return dp[start][end];
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> m;

	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][i] = 1;
		if (arr[i - 1] == arr[i]) dp[i - 1][i] = 1;
	}

	while (m--) {
		int s, e;
		cin >> s >> e;
		if (s >= e) {
			int temp = s;
			s = e;
			e = temp;
		}

		cout << DP(s, e) << '\n';
	}
}