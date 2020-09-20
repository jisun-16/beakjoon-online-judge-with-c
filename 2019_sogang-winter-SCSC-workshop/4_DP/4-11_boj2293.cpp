#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int  n, k;
int coin[101], dp[10001];

int main() {
	cin >> n >> k;

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << endl;
}