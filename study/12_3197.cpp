#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int r,c;
int area_num[1501][1501];
char lake[1501][1501];
bool visited[1501][1501];
pair<int,int> swan;
queue<pair<int,int> > water_q,water_nq,swan_q,swan_nq;

bool avail(int x,int y){
	return x>=0&&x<r&&y>=0&&y<c;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			cin>>lake[i][j];
			if(lake[i][j]=='L')
				swan={i,j};
			if(lake[i][j]!='X') water_q.push({i,j});
		}
	
	int ans=0,fin=false;
	swan_q.push({swan});
	visited[swan.first][swan.second]=true;
	while(true){
		while(!swan_q.empty()&&!fin){
			int x=swan_q.front().first,y=swan_q.front().second;
			swan_q.pop();
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(!avail(nx,ny)||visited[nx][ny]) continue;
				visited[nx][ny]=true;
				if(lake[nx][ny]=='.')
					swan_q.push({nx,ny});
				else if(lake[nx][ny]=='X')
					swan_nq.push({nx,ny});
				else if(lake[nx][ny]=='L'){
					fin=true;
					break;
				}	
			}
		}//만날 수 있는지 체크 
		
		if(fin){
			cout<<ans<<'\n';
			return 0;
		}
		
		while(!water_q.empty()){
			int x=water_q.front().first,y=water_q.front().second;
			water_q.pop();
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(!avail(nx,ny)) continue;
				if(lake[nx][ny]=='X'){
					lake[nx][ny]='.';
					water_nq.push({nx,ny});
				}
			}
		}//얼음->물 
		
		water_q=water_nq;
		swan_q=swan_nq;
		water_nq=queue<pair<int,int> >();
		swan_nq=queue<pair<int,int> >();
		ans++;
	}
}
