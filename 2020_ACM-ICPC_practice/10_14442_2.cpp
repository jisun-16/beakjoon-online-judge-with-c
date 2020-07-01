#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,k,check[1001][1001];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char map[1001][1001]; 

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			check[i][j]=k+1;
		}
	}
	
	queue<pair<pair<int,int>,pair<int,int> > > q;
	q.push({{1,1},{0,1}});
	check[1][1]=0;
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int block=q.front().second.first;
		int dist=q.front().second.second;
		q.pop();
		
		if(x==n&&y==m){
			cout<<dist<<'\n';
			return 0;
		}
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i],nd=dist+1,nk=block;
			
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			if(check[nx][ny]<=nk) continue;//이미 체크했음 
			
			if(map[nx][ny]=='0') check[nx][ny]=nk; 
			else{
				if(nk>=k) continue;
				check[nx][ny]=++nk;
			}
			
			q.push({{nx,ny},{nk,nd}});
		}
	}
	
	cout<<-1<<'\n';
}
