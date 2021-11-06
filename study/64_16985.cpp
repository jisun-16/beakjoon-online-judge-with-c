#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int maze[5][4][5][5],arr[5][5][5],ord[5]={0,1,2,3,4},ans=987654321;
int dx[]={0,0,-1,0,1,0},dy[]={0,0,0,-1,0,1},dz[]={-1,1,0,0,0,0};
void bfs(){
	bool visited[5][5][5]={0,};
	int cnt=0;
	queue<pair<int,pair<int,int> > > q;
	q.push({0,{0,0}});
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int x=q.front().first,y=q.front().second.first,z=q.front().second.second;
			q.pop();
			if(x==4&&y==4&&z==4){
				ans=ans<cnt?ans:cnt;
				return;
			}
			for(int i=0;i<6;++i){
				int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
				if(nx<0||nx>=5||ny<0||ny>=5||nz<0||nz>=5) continue;
				if(!arr[nx][ny][nz]||visited[nx][ny][nz]) continue;
				visited[nx][ny][nz]=true;
				q.push({nx,{ny,nz}});
			}
		}
		cnt++;
	}
}
void perm(int idx){
	if(idx==5){
		
	for(int a=0;a<4;++a)
		for(int b=0;b<4;++b)
			for(int c=0;c<4;++c)
				for(int d=0;d<4;++d)
					for(int e=0;e<4;++e){
						for(int i=0;i<5;++i)
							for(int j=0;j<5;++j){
								arr[0][i][j]=maze[ord[0]][a][i][j];
								arr[1][i][j]=maze[ord[1]][b][i][j];
								arr[2][i][j]=maze[ord[2]][c][i][j];
								arr[3][i][j]=maze[ord[3]][d][i][j];
								arr[4][i][j]=maze[ord[4]][e][i][j];
							}
						if(!arr[0][0][0]||!arr[4][4][4]) continue;
						bfs();
					}
					
	}
	for(int i=idx;i<5;++i){
		swap(ord[i],ord[idx]);
		perm(idx+1);
		swap(ord[i],ord[idx]);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<5;++i)
		for(int r=0;r<5;++r)
			for(int c=0;c<5;++c){
				cin>>maze[i][0][r][c];
				maze[i][1][c][4-r]=maze[i][0][r][c];
				maze[i][2][4-r][4-c]=maze[i][0][r][c];
				maze[i][3][4-c][r]=maze[i][0][r][c];
			}
	perm(0);
	cout<<(ans==987654321?-1:ans);
}
