#include<iostream>
#include<algorithm>

using namespace std;

int t, n;
long long dp[2][21], C[21][21];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	C[0][0]=1;
	for(int i=1;i<=20;i++){
		C[i][0]=1;
		C[i][i]=1;
		for(int j=1;j<i;j++) 
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	
	dp[0][1]=1;dp[0][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=20;i++){
		for(int j=0;j<i;j++){
			dp[j%2][i]+=dp[j%2][j]*dp[0][i-j-1]*C[i-1][j];
		}
	}
	
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1) cout<<1<<'\n';
		else cout<<dp[0][n]+dp[1][n]<<'\n';
	}
}
