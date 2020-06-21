#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},cnt;
int map[101][101], visited[101][101];

void _dfs(int x, int y, int c){
	map[x][y]=c;
	visited[x][y]=true;
	
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(visited[nx][ny]) continue;
		
		if(map[nx][ny]) _dfs(nx,ny,c);
	}
}

int _bfs(int cc){
	queue<pair<int,int> > q;
	memset(visited,false,sizeof(visited));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(map[i][j]==cc){
				visited[i][j]=true;
				q.push({i,j});
			}
	
	int ret=0;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int x=q.front().first,y=q.front().second;
			q.pop();
			
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				
				if(nx<0||nx>=n||ny<0||ny>=n) continue;
				if(map[nx][ny]&&map[nx][ny]!=cc) return ret;
				if(!map[nx][ny]&&!visited[nx][ny]){
					visited[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
		ret++;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>map[i][j];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(map[i][j]&&!visited[i][j])
				_dfs(i,j,++cnt);
	}//섬별로 표시함 : 1,2,...,cnt  
	
	int ans=987654321;
	for(int i=1;i<=cnt;i++){
		int temp=_bfs(i);
		if(ans>temp) ans=temp;
	}
	
	cout<<ans<<'\n';
}
