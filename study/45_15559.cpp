#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans,cnt[1001][1001];
char map[1001][1001];
int dfs(int x,int y,int d){
	if(cnt[x][y]) return cnt[x][y];
	cnt[x][y]=d;
	int nx,ny;
	if(map[x][y]=='N') nx=x-1,ny=y;
	else if(map[x][y]=='S') nx=x+1,ny=y;
	else if(map[x][y]=='W') nx=x,ny=y-1;
	else nx=x,ny=y+1;
	cnt[x][y]=dfs(nx,ny,d);
	return cnt[x][y];
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>map[i];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(!cnt[i][j]){
				cnt[i][j]=dfs(i,j,ans+1);
				ans=max(ans,cnt[i][j]);
			}
	cout<<ans<<'\n';
}
