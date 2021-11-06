#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0},ans=0;
int m,n;
char arr[50][51];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=0;i<m;++i)
		cin>>arr[i];
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j){
			if(arr[i][j]=='W') continue;
			bool visited[50][50]={0,};
			queue<pair<int,int> > q;
			int m_dist=0;
			visited[i][j]=true;
			q.push({i,j});
			while(!q.empty()){
				int s=q.size();
				while(s--){
					int x=q.front().first,y=q.front().second;
					q.pop();
					for(int d=0;d<4;++d){
						int nx=x+dx[d],ny=y+dy[d];
						if(nx<0||nx>=m||ny<0||ny>=n) continue;
						if(visited[nx][ny]||arr[nx][ny]=='W') continue;
						visited[nx][ny]=true;
						q.push({nx,ny});
					}
				}
				++m_dist;
			}
			ans=ans>=m_dist-1?ans:m_dist-1;
		}
	cout<<ans<<'\n';
}
