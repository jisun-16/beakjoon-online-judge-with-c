#include<iostream>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int inf = 10000000;
int n, m, r;
int item[101], dp[101][101];

int main() {
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = inf;
		}
		dp[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) cin >> item[i];

	for (int i = 1; i <= r; i++ ){
		int a, b, l;
		cin >> a >> b >> l;
		dp[a][b] = min(l, dp[a][b]);
		dp[b][a] = min(l, dp[b][a]);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m) {
				temp += item[j];
			}
		}
		if (temp > ans) ans = temp;
	}

	cout << ans << endl;
}