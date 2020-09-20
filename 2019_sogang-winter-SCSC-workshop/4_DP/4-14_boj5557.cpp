#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, num[101];
long long dp[101][21];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> num[i];

	dp[1][num[1]] = 1;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i][j] > 0) {
				if (j + num[i+1] <= 20 ) {
					dp[i+1][j + num[i+1]] += dp[i][j];
				}
				if(j - num[i+1] >= 0)
					dp[i+1][j - num[i+1]] += dp[i][j];
			}
		}
	}

	cout << dp[n-1][num[n]] << endl;
	
	return 0;
}