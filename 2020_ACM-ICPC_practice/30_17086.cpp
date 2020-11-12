#include<cstdio>
#include<queue>

#define pii pair<int,int>

using namespace std;

int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};
int n,m,arr[50][50],dist[50][50];
queue<pii> q;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			dist[i][j]=-1;
			scanf("%d",&arr[i][j]);
			if(arr[i][j]) {
				q.push({i,j});
				dist[i][j]=0;
			}
		}
	
	int d=0;
	while(!q.empty()){
		int temp=q.size();
		d++;
		while(temp--){
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int i=0;i<8;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(nx<0||nx>=n||ny<0||ny>=m) continue;
				if(dist[nx][ny]!=-1) continue;
				dist[nx][ny]=d;
				q.push({nx,ny});
			}
		}
	}
	
	int ans=-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(ans<dist[i][j]) ans=dist[i][j];
			
	printf("%d\n",ans);
}	

