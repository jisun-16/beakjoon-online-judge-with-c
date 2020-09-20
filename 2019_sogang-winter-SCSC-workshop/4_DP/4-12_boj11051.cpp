#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int  n, k;
int dp[1001][1001];

int main() {
	cin >> n >> k;

	for(int i=0;i<=n;i++) {
dp[i][0]=1;
dp[i][i]=1;
    }
    
    for(int i=2;i<=n;i++){
for(int j=1;j<i;j++){
dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
}
}

	cout << dp[n][k] << endl;
}