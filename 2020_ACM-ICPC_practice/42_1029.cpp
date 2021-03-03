#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,dp[15][10][1<<15+1];
string cost[15];
int sol(int now,int p,int b){
	int &ret=dp[now][p][b];
	if(ret!=-1) return ret;
	b|=(1<<now);
	ret=0;
	for(int i=0;i<n;++i){
		if((now!=i)&&(cost[now][i]-'0'>=p)&&((b&(1<<i))==0))
			ret=max(ret,sol(i,cost[now][i]-'0',b));
	}
	b^=(1<<now);
	++ret;
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>cost[i];
	memset(dp,-1,sizeof(dp));
	cout<<sol(0,0,0)<<'\n';
}
