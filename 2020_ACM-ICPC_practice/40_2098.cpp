#include<iostream>
#include<algorithm>
using namespace std;
int n,cost[16][16],inf=1e10,dp[16][1<<16];
int TSP(int u, int v){
	if(v==(1<<n)-1) return cost[u][0]>0?cost[u][0]:inf;
	int &ret=dp[u][v];
	if(ret>0) return ret;
	ret=inf;
	for(int i=0;i<n;++i)
		if(!(v&(1<<i))&&cost[u][i]>0)
			ret=min(ret,TSP(i,v|(1<<i))+cost[u][i]);
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>cost[i][j];
		}
	}
	cout<<TSP(0,1)<<'\n';
}
