#include<iostream>
#include<algorithm>

using namespace std;

const int mod=10007;
int t,n;
int dp[50001][2];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	dp[1][0]=1;
	dp[2][0]=4;dp[2][1]=3;
	for(int i=3;i<=50000;i++){
		dp[i][0]=(dp[i-1][0]*3+dp[i-1][1])%mod;
		dp[i][1]=(dp[i-1][0]*2+dp[i-1][1])%mod;
	}
	
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n][0]<<' '<<(dp[n][0]+dp[n][1]-1)*n%mod<<'\n';
	}
}
