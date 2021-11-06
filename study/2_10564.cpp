#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int t, n, m, s[11], dp[5001][5001]; //dp[누적][점수]

void solve(int cnt, int score) {
	for (int i = 0; i < m; i++) {
		if (cnt + score + s[i] > n || dp[cnt + score + s[i]][score + s[i]]) continue;
		dp[cnt + score + s[i]][score + s[i]] = 1;
		solve(cnt + score + s[i], score + s[i]);
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;

		for (int i = 0; i <= n; i++)
			memset(dp[i], 0, sizeof(dp[i]));

		for (int i = 0; i < m; i++) {
			cin >> s[i];
			dp[s[i]][s[i]] = 1;
		}

		for (int i = 0; i < m; i++) solve(s[i], s[i]);

		bool ans = false;
		for(int i = n; i > 0; i--)
			if (dp[n][i]) {
				cout << i << '\n';
				ans = true;
				break;
			}
		if (!ans) cout << -1 << '\n';
	}
}