#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int n,m,dist[51][51][4][4];
char map[51][51];
pair<int,int> me;

int cx,cy,ex,ey;

struct node{
	int x,y,dir,cnt;
	node(int x,int y,int dir,int cnt):
		x(x),y(y),dir(dir),cnt(cnt){}
};

bool avail(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char temp;
			cin>>temp;
			if(temp=='S') me={i,j};
			if(temp=='C'){
				cx=i;
				cy=j;
			}
			map[i][j]=temp;
		}
	}
	
	memset(dist,-1,sizeof(dist));
	queue<node> q;
	for(int i=0;i<4;i++){
		q.push(node(me.first,me.second,i,0));
		dist[me.first][me.second][i][0]=0;
	}
	bool fin=false;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(now.dir==i) continue;
			
			node next=now;
			next.x+=dx[i];next.y+=dy[i];next.dir=i;
			
			if(!avail(next.x,next.y)) continue;
			if(dist[next.x][next.y][next.dir][next.cnt]!=-1) continue;
			if(map[next.x][next.y]=='#') continue;
			
			if(map[next.x][next.y]=='C'){
				if(next.x==cx&&next.y==cy)
					next.cnt|=1;
				else
					next.cnt|=2;
				
				if(next.cnt==3){
					ex=next.x;ey=next.y;
					fin=true;
				}
			}
			dist[next.x][next.y][next.dir][next.cnt]=dist[now.x][now.y][now.dir][now.cnt]+1;
			q.push(next);
			
			if(fin) break;
		}
		if(fin) break;
	}
	
	if(!fin) cout<<-1<<'\n';
	else{
		int ans=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				ans=max(ans,dist[ex][ey][i][j]);
		}
		cout<<ans<<'\n';
	}
}
