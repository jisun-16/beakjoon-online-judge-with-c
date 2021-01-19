#include<cstdio>
#include<queue>

#define pii pair<int,int>

using namespace std;

int two[7]={1,2,4,8,16,32,64};
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int N,np,Q,arr[64][64];
queue<pii> q;

void rot(int x,int y,int s){
	int l=s-1;
	for(int i=0;i<s/2;++i,l-=2){
		for(int a=0;a<l;++a){
			int temp=arr[x+i][y+i+a];
			arr[x+i][y+i+a]=arr[x+i+l-a][y+i];
			arr[x+i+l-a][y+i]=arr[x+i+l][y+i+l-a];
			arr[x+i+l][y+i+l-a]=arr[x+i+a][y+i+l];
			arr[x+i+a][y+i+l]=temp;
		}
	}
}

int main(){
	scanf("%d %d",&N,&Q);
	np=two[N];
	for(int i=0;i<np;++i)
		for(int j=0;j<np;++j) scanf("%d",&arr[i][j]);
	
	while(Q--){
		int l;
		scanf("%d",&l);
		int lp=two[l];
		
		if(l!=0){
			for(int r=0;r<np;r+=lp)
				for(int c=0;c<np;c+=lp)
					rot(r,c,lp);
		}
		
		for(int r=0;r<np;++r)
			for(int c=0;c<np;++c){
				if(arr[r][c]){
					int cnt=(r-1>=0&&arr[r-1][c]?1:0)+(c-1>=0&&arr[r][c-1]?1:0)+(r+1<np&&arr[r+1][c]?1:0)+(c+1<np&&arr[r][c+1]?1:0);
					if(cnt<3) q.push({r,c});
				}
			}
			
		
		while(!q.empty()){
			pii now=q.front();
			q.pop();
			arr[now.first][now.second]--;
		}
	}
	
	//sum, bfs
	int sum=0,max_size=0;
	
	bool visited[64][64]={0,};
	for(int i=0;i<np;++i)
		for(int j=0;j<np;++j){
			sum+=arr[i][j];
			
			if(visited[i][j]||arr[i][j]==0) continue;
			
			visited[i][j]=true;
			q.push({i,j});
			int size=1;
			while(!q.empty()){
				pii now=q.front();
				q.pop();
				for(int d=0;d<4;++d){
					int nx=now.first+dx[d],ny=now.second+dy[d];
					
					if(nx<0||nx>=np||ny<0||ny>=np) continue;
					if(visited[nx][ny]||arr[nx][ny]==0) continue;
					
					++size;
					visited[nx][ny]=true;
					q.push({nx,ny});
				}
			}
			
			if(max_size<size) max_size=size;
		}
	
	printf("%d\n%d\n",sum,max_size);
}
