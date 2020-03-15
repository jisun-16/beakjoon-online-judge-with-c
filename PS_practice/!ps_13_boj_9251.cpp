#include<iostream>
#include<algorithm>

using namespace std;
int dp[1001][1001];
int main() {
	string a, b;
	cin >> a >> b;
	
	int m = a.length(), n = b.length();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] == b[j - 1]) 
				dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[m][n] << endl;
}