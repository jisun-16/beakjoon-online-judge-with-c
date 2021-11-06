#include<cstdio>
#include<queue>
using namespace std;
int N,M,arr[102][102];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1},visited[102][102];
int main(){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			scanf("%1d",&arr[i][j]);
	
	queue<pair<int,int> > q;
	q.push({1,1});
	visited[1][1]=1;
	
	while(!q.empty()){
		int s=q.size();
		while(s--){
			int x=q.front().first,y=q.front().second;
			q.pop();
			if(x==N&&y==M){
				printf("%d\n",visited[x][y]);
				return 0;
			}
			for(int i=0;i<4;++i){
				int nx=x+dx[i],ny=y+dy[i];
				if(visited[nx][ny]||arr[nx][ny]==0) continue;
				q.push({nx,ny});
				visited[nx][ny]=visited[x][y]+1;
			}
		}
	}
}
