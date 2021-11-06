#include<iostream>
#include<cstring>
using namespace std;
int b[3],k[2],dp[501][501][2];
char winner(int k1,int k2,int w){
	if(dp[k1][k2][w]!=-1) 
		return dp[k1][k2][w];
	for(int i=0;i<3;++i)
		if(b[i]<=k1&&!winner(k1-b[i],k2,1-w))
			return dp[k1][k2][w]=1;
	for(int i=0;i<3;++i)
		if(b[i]<=k2&&!winner(k1,k2-b[i],1-w))
			return dp[k1][k2][w]=1;
	return dp[k1][k2][w]=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>b[0]>>b[1]>>b[2];
	for(int i=0;i<5;++i){
		memset(dp,-1,sizeof(dp));
		cin>>k[0]>>k[1];
		int res=winner(k[0],k[1],0);
		cout<<(res?'A':'B')<<'\n';
	}
}
