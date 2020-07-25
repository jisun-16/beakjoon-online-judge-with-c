#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[46];
int fibo(int n) {
	if (dp[n]) return dp[n];
	if (n == 0) return 0;
	dp[n] = fibo(n - 1) + fibo(n - 2);
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	cout << fibo(n);
}//그냥 접근하면 시간초과