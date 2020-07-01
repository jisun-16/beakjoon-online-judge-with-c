#include<iostream>
#include<queue>

using namespace std;

int n,m,k,map[1001][1001];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int check[1001][1001];

typedef struct node{
	int x,y,block,dist;
	node(int x,int y,int block,int dist):x(x),y(y),block(block),dist(dist){}
}node;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char temp;
			cin>>temp;
			map[i][j]=temp-'0';
			check[i][j]=k+1;
		}
	
	queue<node> q;
	q.push({1,1,0,1});
	check[1][1]=0;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		
		if(now.x==n&&now.y==m){
			cout<<now.dist<<'\n';
			return 0;
		}
		
		for(int i=0;i<4;i++){
			node next=now;
			next.x+=dx[i];next.y+=dy[i];next.dist++;
			int nx=next.x,ny=next.y,nk=next.block;
			
			if(nx<=0||nx>n||ny<=0||ny>m) continue;
			if(check[nx][ny]<=nk) continue;
			
			if(map[nx][ny]==1){
				if(nk>=k) continue;
				if(now.dist%2==0){
					next=now;
					next.dist++;
				}
				else{
					check[nx][ny]=nk;
					next.block++;
				}
			}
			if(map[nx][ny]==0)
				check[nx][ny]=nk;
				
			q.push(next);
		}
	}
	
	cout<<-1<<'\n';
}
