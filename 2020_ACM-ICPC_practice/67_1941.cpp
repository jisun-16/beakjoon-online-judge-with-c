#include<iostream>
#include<queue>
using namespace std;
char arr[5][6];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1},ans;
void bfs(int x,int y){
	bool visited[5][5]={0,};
	queue<pair<string,pair<int,int> > > q;
	visited[x][y]=true;
	q.push({""+arr[x][y],{x,y}});
	while(!q.empty()){
		int i=q.front().second.first,j=q.front().second.second;
		string s=q.front().first;
		q.pop();
		if(s.length()==7){
			ans++;
			continue;
		}
		for(int d=0;d<4;++d){
			int ni=i+dx[d],nj=j+dy[d];
			if(ni<0||ni>=5||nj<0||nj>=5) continue;
			if(visited[ni][nj]) continue;
			visited[ni][nj]=true;
			q.push({s+arr[ni][nj],{ni,nj}});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<5;++i)
		cin>>arr[i];
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j){
			bfs(i,j);
		}
	cout<<ans;
}
