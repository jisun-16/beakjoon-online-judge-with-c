#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n,m,maze[101][101];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int cnt[101][101];

int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&maze[i][j]);
			cnt[i][j]=-1;
		}
	}
	
	queue<pair<int,int> > q;
	queue<pair<int,int> > q2;
	
	q.push({1,1});
	cnt[1][1]=0;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		
		cout<<x<<' '<<y<<' '<<cnt[x][y]<<'\n';
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			if(cnt[nx][ny]!=-1) continue;
			
			cnt[nx][ny]=cnt[x][y]+maze[nx][ny];
			if(maze[nx][ny]==0) q.push({nx,ny});
			else q2.push({nx,ny});
		}
		
		if(q.empty()) swap(q,q2);
	}
	
	printf("%d\n",cnt[n][m]);
}
