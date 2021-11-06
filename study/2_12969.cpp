#include<iostream>
#include<algorithm>

using namespace std;

int N, K, dp[31][31][31][450];//dp[a][b][n][k]
char ans[31];

int DP(int a, int b, int n, int k) {
	if (n == N) {
		if (k == K) return 1;
		else return 0;
	}

	if (dp[a][b][n][k] == 1) return 0;
	dp[a][b][n][k] = 1;

	ans[n] = 'C';
	if (DP(a, b, n + 1, k + a + b) == 1) return 1;

	ans[n] = 'B';
	if (DP(a, b + 1, n + 1, k + a) == 1) return 1;

	ans[n] = 'A';
	if (DP(a + 1, b, n + 1, k) == 1) return 1;

	return 0;
}

int main() {
	cin >> N >> K;

	if (DP(0, 0, 0, 0)) cout << ans << '\n';
	else cout << -1 << '\n';

	return 0;
}