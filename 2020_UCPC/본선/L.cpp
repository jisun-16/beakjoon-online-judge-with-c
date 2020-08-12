#include<iostream>

using namespace std;

int n,pizza[1001];
int dp[1001][1001];

int _solve(int s, int cnt, int diff){
	if(cnt==0){
		return diff;
	}
	
	if(diff<=0){
		return max(_solve((s+1)%n,cnt-1,diff+pizza[s]),_solve(s,cnt-1,diff+pizza[(s+cnt-1)%n]));
	}
	else{
		return min(_solve((s+1)%n,cnt-1,diff-pizza[s]),_solve(s,cnt-1,diff-pizza[(s+cnt-1)%n]));
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++) {
		cin>>pizza[i];
		sum+=pizza[i];
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		ans=min(ans,_solve((i+1)%n,n-1,pizza[i]));
	}
	
	ans=(sum+ans)/2;
	cout<<ans<<'\n';
}
