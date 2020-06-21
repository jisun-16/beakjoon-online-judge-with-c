#include<iostream>
#include<algorithm>

using namespace std;

int r, c, visited[10001][501];
bool map[10001][501];
int dx[3]={1,1,1},dy[3]={-1,0,1};

int _dfs(int y, int x){
	if(x==c-2) return 1;
	
	for(int i=0;i<3;i++){
		if(y+dy[i]<0||y+dy[i]>=r||!map[y+dy[i]][x+dx[i]]) continue;
		if(visited[y+dy[i]][x+dx[i]]) continue;
		visited[y+dy[i]][x+dx[i]]=true;
		if(_dfs(y+dy[i],x+dx[i])) return 1;
	}
	
	return 0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char temp;
			cin>>temp;
			if(temp=='x') map[i][j]=false;
			else map[i][j]=true;
		}
	}
	
	int ans=0;
	for(int i=0;i<r;i++){
		ans+=_dfs(i,0);
	}
	
	cout<<ans<<'\n';
}
