#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,k,map[1001][1001],check[1001][1001][11]={0,};
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		string temp;
		cin>>temp;
		for(int j=1;j<=m;j++){
			map[i][j]=temp[j-1]-'0';
		}
	}
	
	queue<pair<pair<int,int>,int> > q;
	q.push({{1,1},k});
	check[1][1][k]=1;
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int block=q.front().second;
		q.pop();
		
		
		if(x==n&&y==m){
			cout<<check[n][m][block]<<'\n';
			return 0;
		}
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			
			if(map[nx][ny]==1&&check[nx][ny][block-1]==0){
				if(block==0) continue;
				q.push({{nx,ny},block-1});
				check[nx][ny][block-1]=check[x][y][block]+1;
			}
			if(map[nx][ny]==0&&check[nx][ny][block]==0){
				q.push({{nx,ny},block});
				check[nx][ny][block]=check[x][y][block]+1;
			}
		}
	}
	
	cout<<-1<<'\n';
}
