#include<iostream>
#include<algorithm>

using namespace std;

int n,m,dx[3]={1,0,1},dy[3]={0,1,1};
int maze[1001][1001], dp[1001][1001];
int ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>maze[i][j];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+maze[i][j];
		}
	}
	
	cout<<dp[n][m]<<'\n';
}
