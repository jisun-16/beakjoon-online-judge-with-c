#include<iostream>

using namespace std;

int n,arr[1001],dp[1001],ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]&&dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
		
		if(dp[i]>ans) ans=dp[i];
	}
	
	cout<<ans<<'\n';
}
