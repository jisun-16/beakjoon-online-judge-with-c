#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

#define pii pair<int,int>

const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int n,m,ans;
int hei[52][52];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%1d",&hei[i][j]);
	
	//���̰� 1�� �׵θ��� ���� 
	for(int i=0;i<=n+1;i++) hei[i][0]=hei[i][m+1]=1;
	for(int j=0;j<=m+1;j++) hei[0][j]=hei[n+1][j]=1;
	
	for(int i=1;i<=9;i++){
		//�׵θ����� �־��� ���̸�ŭ bfs 
		queue<pii> q;
		q.push({0,0});
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int d=0;d<4;d++){
				int nx=x+dx[d],ny=y+dy[d];
				if(nx<0||nx>n+1||ny<0||ny>m+1) continue;
				if(hei[nx][ny]<i){
					hei[nx][ny]=i;
					q.push({nx,ny});
				}
			}
		}
		
		//bfs�� ä������ ���� �κе��� ans�� �����ش� 
		for(int r=1;r<=n;r++)
			for(int c=1;c<=m;c++)
				if(hei[r][c]<i){
					ans+=i-hei[r][c];
					hei[r][c]=i;
				}
	}
	
	printf("%d\n",ans);
}
