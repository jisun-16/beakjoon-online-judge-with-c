#include<iostream>
#include<algorithm>

using namespace std;

int n,a,b,sum,dp[62501];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	for(int i=0;i<=62500;i++)
		dp[i]=1e9;
	
	cin>>n;
	dp[0]=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		sum+=a;
		for(int j=sum;j>=a;j--){
			dp[j]=min(dp[j],dp[j-a]+b);
		}
	}
	
	int ans=1e9;
	for(int i=0;i<=62500;i++){
		ans=min(ans,max(sum-i,dp[i]));
	}
	
	cout<<ans<<'\n';
}
