#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

struct node{
	int x,y,chk,chg,p;
	node(int x,int y,int chk,int chg,int p):
		x(x),y(y),chk(chk),chg(chg),p(p){}
};

int inf=987654321;
int dx[3][8]={{-2,-2,-1,-1,1,1,2,2},{-1,-1,1,1,0,0,0,0},{-1,0,1,0,0,0,0,0}};
int dy[3][8]={{-1,1,-2,2,-2,2,-1,1},{-1,1,-1,1,0,0,0,0},{0,1,0,-1,0,0,0,0}};
int n,map[11][11],dist[11][11][101][3];
queue<node> q;

bool avail(int x,int y){
	return x>=0&&x<n&&y>=0&&y<n;
}

int main(){
	for(int i=0;i<11;i++)
		for(int j=0;j<11;j++)
			for(int k=0;k<101;k++)
				for(int l=0;l<3;l++) dist[i][j][k][l]=inf;
	
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				q.push({i,j,1,0,0});//knight
				dist[i][j][1][0]=0;
				q.push({i,j,1,0,1});//bishop
				dist[i][j][1][1]=0;
				q.push({i,j,1,0,2});//rook
				dist[i][j][1][2]=0;
			}
		}
	
	int time=0,cnt=inf;
	bool end=false;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			node now=q.front();
			q.pop();
			
			if(now.chk==n*n){
				end=true;
				cnt=min(cnt,now.chg);
				continue;
			}
			
			int d=(now.p==0)? 8:4;
			for(int i=0;i<d;i++){
				for(int k=1;;k++){
					node next=now;
					next.x=now.x+k*dx[now.p][i];
					next.y=now.y+k*dy[now.p][i];
					
					if(!avail(next.x,next.y)) break;
					
					if(map[next.x][next.y]==now.chk+1) next.chk=now.chk+1;
					
					if(dist[next.x][next.y][next.chk][next.p]>now.chg){
						dist[next.x][next.y][next.chk][next.p]=now.chg;
						q.push(next);
					}
					
					if(now.p==0) break;
				}
			}
			
			for(int i=0;i<3;i++){
				if(i==now.p) continue;
				node next=now;
				next.chg++;
				next.p=i;
				
				if(dist[next.x][next.y][next.chk][next.p]>next.chg){
					dist[next.x][next.y][next.chk][next.p]=next.chg;
					q.push(next);
				}
			}
		}
		
		if(end) break;
		time++;
	}
	
	cout<<time<<' '<<cnt<<'\n';
}
