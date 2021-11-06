#include<iostream>
#include<queue>
using namespace std;
int n,arr[100][100],ans=1;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j) cin>>arr[i][j];
	for(int i=1;i<100;++i){
		bool drown[100][100]={0,};
		for(int r=0;r<n;++r)
			for(int c=0;c<n;++c)
				if(arr[r][c]<=i) drown[r][c]=true;
		int cnt=0;
		bool visited[100][100]={0,};
		for(int r=0;r<n;++r)
			for(int c=0;c<n;++c){
				if(visited[r][c]||drown[r][c]) continue;
				cnt++;
				queue<pair<int,int> > q;
				q.push({r,c});
				visited[r][c]=true;
				while(!q.empty()){
					int x=q.front().first,y=q.front().second;
					q.pop();
					for(int d=0;d<4;d++){
						int nx=x+dx[d],ny=y+dy[d];
						if(nx<0||nx>=n||ny<0||ny>=n||visited[nx][ny]||drown[nx][ny]) continue;
						q.push({nx,ny});
						visited[nx][ny]=true;
					}
				}
			}
		if(cnt>ans) ans=cnt;
	}
	cout<<ans;
}
