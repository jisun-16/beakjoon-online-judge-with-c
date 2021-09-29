#include<iostream>
#include<queue>
using namespace std;
int N,M,sx,sy,dist[50][50][64];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
char maze[50][50];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>M>>N;
	for(int i=0;i<M;++i){
		cin>>maze[i];
		for(int j=0;j<N;++j)
			if(maze[i][j]=='0') sx=i,sy=j;
	}
	
	queue<pair<pair<int,int>,int> > q;
	q.push({{sx,sy},0});
	while(!q.empty()){
		int x=q.front().first.first,y=q.front().first.second,bm=q.front().second;
		q.pop();
		if(maze[x][y]=='1')	{
			cout<<dist[x][y][bm];
			return 0;
		}
		for(int d=0;d<4;++d){
			int nx=x+dx[d],ny=y+dy[d],k=bm;
			if(nx<0||nx>=M||ny<0||ny>=N||maze[nx][ny]=='#') 
				continue;			
			if(maze[nx][ny]>='a'&&maze[nx][ny]<='f')
				k|=(1<<(maze[nx][ny]-'a'));
			else if(maze[nx][ny]>='A'&&maze[nx][ny]<='F')
				if(!(k&(1<<(maze[nx][ny]-'A')))) 
					continue;
			if(!dist[nx][ny][k]) {
				q.push({{nx,ny},k});
				dist[nx][ny][k]=dist[x][y][bm]+1;
			}
		}
	}
	
	cout<<-1;
}
