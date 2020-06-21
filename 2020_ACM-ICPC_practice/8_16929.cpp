#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n,m,s_x,s_y;
char board[51][51];
bool visited[51][51], ans;

int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

void _solve(int cnt, int x, int y){
	if(ans) return;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(board[nx][ny]!=board[s_x][s_y]) continue;
		
		if(visited[nx][ny]){
			if(cnt>=4&&s_x==nx&&s_y==ny){
				ans=true;
				return;
			}
		}
		else{
			visited[nx][ny]=true;
			_solve(cnt+1,nx,ny);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>board[i][j];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			memset(visited, false,sizeof(visited));
			
			s_x=i;s_y=j;
			visited[i][j]=true;
			_solve(1,i,j);
			
			if(ans){
				cout<<"Yes"<<'\n';
				return 0;
			}
		}
	}
	
	cout<<"No"<<'\n';
}
