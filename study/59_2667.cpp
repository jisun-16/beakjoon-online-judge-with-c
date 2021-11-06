#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int N,arr[27][27],apt[400],idx;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1},visited[27][27];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%1d",&arr[i][j]);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j){
			if(visited[i][j]||arr[i][j]==0) continue;
			idx++;
			queue<pair<int,int> > q;
			q.push({i,j});
			visited[i][j]=idx;
			apt[idx-1]++;
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				for(int d=0;d<4;++d){
					int nx=x+dx[d],ny=y+dy[d];
					if(visited[nx][ny]||arr[nx][ny]==0) continue;
					q.push({nx,ny});
					visited[nx][ny]=idx;
					apt[idx-1]++;
				}
			}
		}
	sort(apt,apt+idx);
	printf("%d\n",idx);
	for(int i=0;i<idx;++i) 
		printf("%d\n",apt[i]);
}
