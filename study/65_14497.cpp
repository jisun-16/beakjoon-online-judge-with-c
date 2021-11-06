#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,x1,y1,x2,y2,ans;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
char arr[300][302];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	x1--,y1--,x2--,y2--;
	for(int i=0;i<n;++i) cin>>arr[i];
	while(true){
		queue<pair<int,int> > q;
		bool visited[300][300]={0,};
		q.push({x1,y1});
		visited[x1][y1]=true;
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int d=0;d<4;++d){
				int nx=x+dx[d],ny=y+dy[d];
				if(nx<0||nx>=n||ny<0||ny>=m) continue;
				if(arr[nx][ny]!='0') continue;
				if(visited[nx][ny]) continue;
				q.push({nx,ny});
				visited[nx][ny]=true;
			}
		}
		ans++;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(arr[i][j]=='0'||arr[i][j]=='*') continue;
				bool chk=false;
				for(int d=0;d<4;++d){
					int ni=i+dx[d],nj=j+dy[d];
					if(ni<0||ni>=n||nj<0||nj>=m) continue;
					if(visited[ni][nj]) chk=true;
				}
				if(chk){
					if(arr[i][j]=='#'){
						cout<<ans<<'\n';
						return 0;
					}
					else arr[i][j]='0';
				}
			}
	}
}
