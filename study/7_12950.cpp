#include<iostream>
#include<algorithm>
#include<cstring>

#define inf 987654321

using namespace std;

int n, m, dp[21][21];
char graph[21][21];

int _solve(int x, int y){
	int &ret=dp[x][y];
	
	if(ret!=-1) return ret;
	if((x==0&&y==1)||(x==1&&y==0)) return ret=0;
	
	ret=inf;
	for(int i=0;i<n;i++){
		if(!graph[x][i]) continue;
		for(int j=0;j<n;j++){
			if(!graph[y][j]) continue;
			if(graph[x][i]==graph[j][y])
				ret=min(ret,_solve(i,j)+2);
		}
	}
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	while(m--){
		int a, b;
		char c;
		cin>>a>>b>>c;
		graph[a][b]=c;
		graph[b][a]=c;
	}
	
	memset(dp,-1,sizeof(dp));
	
	int ans=inf;
	for(int i=0;i<n;i++){
		ans=min(ans,_solve(i,i));//0-...-i-...-1
		for(int j=i+1;j<n;j++){
			if(graph[i][j])
				ans=min(ans,_solve(i,j)+1);//0-...-i-j-...-1
		}
	}
	
	if(ans>=inf) cout<<-1<<'\n';
	else cout<<ans<<'\n';
}
