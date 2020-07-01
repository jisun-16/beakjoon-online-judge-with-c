#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m,map[51][51];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};//서-북-동-남
int part_num[51][51],cnt;
vector<int> part_size;
int max_part_size,max_part_size_r;

void _bfs(int a,int b){
	cnt++;
	
	queue<pair<int,int> > q;
	int temp=0;
	
	q.push({a,b});
	part_num[a][b]=cnt;
	temp++;
	
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<=0||nx>m||ny<=0||ny>n) continue;
			if(part_num[nx][ny]) continue;
			
			if((map[x][y]&(1<<i))==0){
				//벽이 없을 때 
				q.push({nx,ny});
				part_num[nx][ny]=cnt;
				temp++;
			}
		}
	}
	
	part_size.push_back(temp);
	if(temp>max_part_size) max_part_size=temp;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) cin>>map[i][j];
	}
	
	part_size.push_back(-1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(part_num[i][j]) continue;
			_bfs(i,j);
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int d=0;d<4;d++){
				int nx=i+dx[d],ny=j+dy[d];
				
				if(nx<=0||nx>m||ny<=0||ny>n) continue;
				
				if((map[i][j]&(1<<d))&&(part_num[i][j]!=part_num[nx][ny]))
					if(part_size[part_num[i][j]]+part_size[part_num[nx][ny]]>max_part_size_r)
						max_part_size_r=part_size[part_num[i][j]]+part_size[part_num[nx][ny]];
			}
		}
	}
	
	cout<<cnt<<'\n';
	cout<<max_part_size<<'\n';
	cout<<max_part_size_r<<'\n';
} 
