#include<iostream>
#include<algorithm>

#define pii pair<int,int>
using namespace std;

int dx[9]={0,-1,-1,0,1,1,1,0,-1},dy[9]={0,0,-1,-1,-1,0,1,1,1};
int arr[4][4],dir[4][4],ans;
pii coor[17];
bool eaten[17];

void mov(int sx,int sy,int eat){
	//eat
	eat+=arr[sx][sy];
	eaten[arr[sx][sy]]=true;
	arr[sx][sy]=0;
	int sd=dir[sx][sy];
	
	ans=max(ans,eat);
	
	//move fish
	for(int i=1;i<=16;i++){
		if(eaten[i]) continue;
		
		int x=coor[i].first,y=coor[i].second;
		int d=dir[x][y];
		int nx=x,ny=y,nd=d-1;
		
		for(int j=0;j<8;j++){
			nd=nd+1==9?1:nd+1;
			nx=x+dx[nd];ny=y+dy[nd];
			if(nx<0||nx>=4||ny<0||ny>=4||(nx==sx&&ny==sy)){
				nx=x;ny=y;
				continue;
			}
			dir[x][y]=nd;
			break;
		}
		
		if(x!=nx||y!=ny){
			if(arr[nx][ny]==0){
				arr[nx][ny]=arr[x][y];
				arr[x][y]=0;
				dir[nx][ny]=dir[x][y];
				coor[i]={nx,ny};
			}
			else{
				int nf=arr[nx][ny];
				arr[nx][ny]=arr[x][y];
				arr[x][y]=nf;
				int nd=dir[nx][ny];
				dir[nx][ny]=dir[x][y];
				dir[x][y]=nd;
				coor[i]={nx,ny};
				coor[nf]={x,y};
			}
		}
	}
	
	//move shark
	for(int i=1;i<4;i++){
		int snx=sx+dx[sd]*i,sny=sy+dy[sd]*i;
		
		if(snx<0||snx>=4||sny<0||sny>=4||arr[snx][sny]==0) continue;
		
		int narr[4][4],ndir[4][4];
		pii ncoor[17];
		bool neaten[17];
		for(int i=0;i<16;i++){
			narr[i/4][i%4]=arr[i/4][i%4];
			ndir[i/4][i%4]=dir[i/4][i%4];
			ncoor[i+1]=coor[i+1];
			neaten[i+1]=eaten[i+1];
		}
		
		mov(snx,sny,eat);
		
		for(int i=0;i<16;i++){
			arr[i/4][i%4]=narr[i/4][i%4];
			dir[i/4][i%4]=ndir[i/4][i%4];
			coor[i+1]=ncoor[i+1];
			eaten[i+1]=neaten[i+1];
		}
	}
}

int main(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			scanf("%d %d",&arr[i][j],&dir[i][j]);
			coor[arr[i][j]]={i,j};
		}
	
	mov(0,0,0);
	
	printf("%d\n",ans);
}
