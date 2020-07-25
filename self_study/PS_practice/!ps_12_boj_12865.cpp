#include<iostream>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

pii item[101];
int dp[101][100001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		item[i].first = w; item[i].second = v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (item[i].first > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].first] + item[i].second);
		}
	}

	cout << dp[n][k] << endl;
}