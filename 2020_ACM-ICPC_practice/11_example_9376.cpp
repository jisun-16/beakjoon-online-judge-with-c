#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<deque>

using namespace std;

int inf=987654321;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int t,h,w,map[102][102],ans;
pair<int,int> pri[2];
int dist[102][102][3];
deque<pair<int,int> > dq;

bool avail(int x,int y){ return x>=0&&x<=h+1&&y>=0&&y<=w+1; }

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>t;
	while(t--){
		memset(map,0,sizeof(map));
		ans=inf;
		
		cin>>h>>w;
		int cnt=0;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				char temp;
				cin>>temp;
				if(temp=='*') map[i][j]=1;
				else if(temp=='#') map[i][j]=-1;
				else{
					map[i][j]=0;
					if(temp=='$') pri[cnt++]={i,j};
				}
			}
		
		vector<pair<int,int> > v;
		v.push_back({0,0});
		v.push_back({pri[0]});
		v.push_back({pri[1]});
		
		for(int i=0;i<3;i++){
			priority_queue<pair<int,pair<int,int> > > pq;
			for(int r=0;r<=h+1;r++)
				for(int c=0;c<=w+1;c++) dist[r][c][i]=inf;
			
			pq.push({0,{v[i]}});
			dist[v[i].first][v[i].second][i]=0;
			
			bool visited[102][102]={false,};
			while(!pq.empty()){
				int x=pq.top().second.first;
				int y=pq.top().second.second;
				pq.pop();
				
				for(int d=0;d<4;d++){
					int nx=x+dx[d],ny=y+dy[d];
					
					if(!avail(nx,ny)) continue;
					if(visited[nx][ny]||map[nx][ny]==1) continue;
					
					int nd=dist[x][y][i];
					if(map[nx][ny]==-1) nd++;
					if(dist[nx][ny][i]>nd){
						dist[nx][ny][i]=nd;
						visited[nx][ny]=true;
						pq.push({-nd,{nx,ny}});
					}
				}
			}
		}
		
		for(int r=1;r<=h;r++){
			for(int c=1;c<=w;c++){
				if(map[r][c]==1) continue;
				
				int summ=0;
				for(int i=0;i<3;i++)
					summ+=dist[r][c][i];
				summ-=2*(map[r][c]==-1);
				ans=min(ans,summ);
			}
		}
		
		cout<<ans<<'\n';
	}
}
