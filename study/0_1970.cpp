#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[1001], dp[1001][1001];//dp[start][end]

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i < n; i++) {
		for (int start = 1; start <= n - i; start++) {
			int end = start + i;
			
			if (arr[start] == arr[end]){
				if(start+1==end) dp[start][end]=1;
				else dp[start][end] = max(dp[start][end], dp[start + 1][end - 1] + 1);
			}
			
			for (int j = start; j < end; j++)
				dp[start][end] = max(dp[start][end], dp[start][j] + dp[j + 1][end]);
		}
	}

	cout << dp[1][n] << '\n';
}
