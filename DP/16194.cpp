#include<iostream>
#include<algorithm>
#define MAX 10000
using namespace std;

int n, price[1001];
int dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> price[i];

	dp[1] = price[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = price[i];
		for (int j = i - 1; j > 0; j--) {
			dp[i] = min(dp[i], dp[i - j] + price[j]);
		}
	}

	cout << dp[n] << '\n';
}