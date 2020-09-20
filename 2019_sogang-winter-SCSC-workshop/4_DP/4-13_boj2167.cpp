#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int n, m, k;
int i, j, x, y;
int dp[301][301];

int main() {
	cin >> n >> m;

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			int temp;
			cin >> temp;
			dp[a][b] = dp[a - 1][b] + dp[a][b - 1] - dp[a - 1][b - 1] + temp;
		}
	}

	cin >> k;

	while (k--) {
		cin >> i >> j >> x >> y;
		int ans = dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1];
		cout << ans << endl;
	}
}