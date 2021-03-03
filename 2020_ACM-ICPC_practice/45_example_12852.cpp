#include<iostream>
#include<stack>
using namespace std;
int n,inf=987654321;
pair<int,int> dp[1000001];
stack<int> ans;
void dfs(int i){
	if(i==0) return;	
	if(i%3==0&&dp[i/3].first>dp[i].first+1){
		dp[i/3].first=dp[i].first+1;
		dp[i].second=1;
		dfs(i/3);
	}
	if(i%2==0&&dp[i/2].first>dp[i].first+1){
		dp[i/2].first=dp[i].first+1;
		dp[i].second=2;
		dfs(i/2);
	}
	if(dp[i-1].first>dp[i].first+1){
		dp[i-1].first=dp[i].first;
		dp[i].second=3;
		dfs(i-1);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<=n;++i) dp[i].first=inf;
	dp[n]={0,0};
	dfs(n);
	cout<<dp[1].first<<'\n';
	int k=1;
	while(k<n){
		ans.push(k);
		if(dp[k].second==1) k*=3;
		else if(dp[k].second==2) k*=2;
		else k++;
	}
	ans.push(n);
	while(!ans.empty()){
		cout<<ans.top()<<' ';
		ans.pop();
	}
}
