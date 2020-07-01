#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;

int n, m, map[1001][1001];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int part_num[1001][1001],cnt;//인접한 0들에 차례대로 넘버링 
bool visited[1001][1001];
vector<int> part_size;

void _bfs(int a,int b){
	int temp=0;
	queue<pair<int,int> > q;
	
	q.push({a,b});
	visited[a][b]=true;
	part_num[a][b]=cnt;
	temp++;
	
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			if(visited[nx][ny]) continue;
			if(map[nx][ny]) continue;
			
			visited[nx][ny]=true;
			part_num[nx][ny]=cnt;
			q.push({nx,ny});
			temp++;
		}
	}
	
	part_size.push_back(temp);
	cnt++;
}

void _solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(visited[i][j]) continue;
			if(map[i][j]!=0) continue;
			
			_bfs(i,j);
		}
	}//0으로 이루어진 part 표시 
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==0) continue;
			
			set<int> s;
			
			for(int d=0;d<4;d++){
				int nx=i+dx[d],ny=j+dy[d];
				
				if(nx<=0||nx>n||ny<=0||ny>m) continue;
				if(map[nx][ny]>0) continue;
				
				if(s.find(part_num[nx][ny])==s.end()){
					s.insert(part_num[nx][ny]);
					map[i][j]+=part_size[part_num[nx][ny]];
				}
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char temp;
			cin>>temp;
			map[i][j]=temp-'0';
		}
	}
	
	_solve();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<map[i][j]%10;
		cout<<'\n';
	}
}
