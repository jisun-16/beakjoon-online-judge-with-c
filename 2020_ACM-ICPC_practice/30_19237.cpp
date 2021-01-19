#include<iostream>
#include<queue>

#define pii pair<int,int>

using namespace std;

int dx[]={0,-1,1,0,0},dy[]={0,0,0,-1,1};
int N,M,K;
int smell[20][20],t[20][20],dir[401],ord[401][5][4];
pii scoor[401];
bool sout[401];

int main(){
	scanf("%d %d %d",&N,&M,&K);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			scanf("%d",&smell[i][j]);
			scoor[smell[i][j]]={i,j};
			t[i][j]=smell[i][j]?0:-1;
		}
	
	for(int i=1;i<=M;i++) scanf("%d",&dir[i]);
	for(int i=1;i<=M;i++){
		for(int j=1;j<=4;j++)
			for(int l=0;l<4;l++){
				scanf("%d",&ord[i][j][l]);
			}
	}
	
	for(int T=1;T<=1000;T++){
		int next[20][20]={0,};
		
		for(int s=1;s<=M;s++){
			if(sout[s]) continue;
			
			int x=scoor[s].first,y=scoor[s].second,d=dir[s],nx=-1,ny=-1;
			
			//ºóÄ­Å½»ö 
			int i=0;
			for(;i<4;i++){
				nx=x+dx[ord[s][d][i]];ny=y+dy[ord[s][d][i]];
				
				if(nx<0||nx>=N||ny<0||ny>=N) continue;
				if(smell[nx][ny]) continue;
				
				if(next[nx][ny]){
					sout[s]=true;
					break;
				}
				
				next[nx][ny]=s;
				scoor[s]={nx,ny};
				t[nx][ny]=T;
				dir[s]=ord[s][d][i];
				break;
			}
			
			//ÀÚ½ÅÀÇ ³¿»õ Å½»ö 
			if(i==4){
				for(i=0;i<4;i++){
					nx=x+dx[ord[s][d][i]];ny=y+dy[ord[s][d][i]];
					
					if(nx<0||nx>=N||ny<0||ny>=N) continue;
					
					if(smell[nx][ny]==s){
						if(next[nx][ny]){
							sout[s]=true;
							break;
						}
						
						next[nx][ny]=s;
						t[nx][ny]=T;
						dir[s]=ord[s][d][i];
						scoor[s]={nx,ny};
						break;
					}
				}
			}
		}
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) {	
				if(t[i][j]+K<=T) smell[i][j]=0;
				if(next[i][j]) smell[i][j]=next[i][j];
			}
			
		
		bool chk=true;
		for(int i=2;i<=M;i++)
			if(!sout[i]){
				chk=false;
				break;
			} 
		
		if(chk){
			printf("%d\n",T);
			return 0;
		}
	}
	printf("-1\n");
}
