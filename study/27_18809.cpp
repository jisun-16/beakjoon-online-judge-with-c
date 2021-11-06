#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define pii pair<int,int>
#define x first
#define y second

using namespace std;

int n,m,g,r,garden[50][50],ans;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
vector<pii> v,vr,vg;

int bfs(){
	int flower=0;
	queue<pii> qr,qg;
	int visited[50][50]={0,};
	bool is_flower[50][50]={0,};	
	
	for(int i=0;i<vr.size();i++){
		visited[vr[i].x][vr[i].y]=1;
		qr.push(vr[i]);
	}
	for(int i=0;i<vg.size();i++){
		visited[vg[i].x][vg[i].y]=1;
		qg.push(vg[i]);
	}
	
	int time=1;
	while(!qr.empty()&&!qg.empty()){
		time++;
		
		int temp=qr.size();
		while(temp--){
			pii now=qr.front();
			qr.pop();
			
			if(is_flower[now.x][now.y]) continue;
			
			for(int d=0;d<4;d++){
				pii next;
				next={now.x+dx[d],now.y+dy[d]};
				
				if(next.x<0||next.x>=n||next.y<0||next.y>=m) continue;
				if(garden[next.x][next.y]==0) continue;
				if(visited[next.x][next.y]) continue;
				
				visited[next.x][next.y]=time;
				qr.push(next);
			}
		}
			
		temp=qg.size();
		while(temp--){
			pii now=qg.front();
			qg.pop();
			
			if(is_flower[now.x][now.y]) continue;
				
			for(int d=0;d<4;d++){
				pii next;
				next={now.x+dx[d],now.y+dy[d]};
					
				if(next.x<0||next.x>=n||next.y<0||next.y>=m) continue;
				if(garden[next.x][next.y]==0) continue;
				if(visited[next.x][next.y]){
					if(visited[next.x][next.y]==time){
						visited[next.x][next.y]=-time;
						flower++;
						is_flower[next.x][next.y]=true;
						continue;
					}
					else continue;
				}
				
				visited[next.x][next.y]=-time;
				qg.push(next);
			}
		}
	}	
	
	return flower;
}

void dfs(int cnt,int R,int G){
	if(R==0&&G==0){
		int flower=bfs();
		ans=max(ans,flower);
		return;
	}
	
	if(v.size()-cnt < R+G) return;
	
	for(int i=cnt;i<v.size();i++){
		if(R){
			vr.push_back(v[i]);
			dfs(i+1,R-1,G);
			vr.pop_back();
		}
		if(G){
			vg.push_back(v[i]);
			dfs(i+1,R,G-1);
			vg.pop_back();
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>g>>r;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>garden[i][j];
			if(garden[i][j]==2)
				v.push_back({i,j});
		}
	
	dfs(0,r,g);
	
	cout<<ans<<'\n';
}
