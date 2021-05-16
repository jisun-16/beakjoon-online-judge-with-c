#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int ans=987654321,s,dx[]={0,0,-1,1},dy[]={-1,1,0,0};
char map[5][6];
vector<pair<int,int> > coor;
void dfs(int cnt,int d){
	if(d>=ans) return;
	if(cnt==s){
		bool chk=true,visited[5][5]={0,};
		int temp=0;
		for(int i=0;i<5&&chk;++i)
			for(int j=0;j<5&&chk;++j){
				if(visited[i][j]||map[i][j]=='.') continue;
				queue<pair<int,int> > q;
				visited[i][j]=true;
				q.push({i,j});
				temp++;
				while(!q.empty()){
					int x=q.front().first,y=q.front().second;
					q.pop();
					for(int d=0;d<4;++d){
						int nx=x+dx[d],ny=y+dy[d];
						if(nx<0||nx>=5||ny<0||ny>=5||visited[nx][ny]||map[nx][ny]=='.') continue;
						visited[nx][ny]=true;
						q.push({nx,ny});
						++temp;
					}
				}
				chk=false;
			}
		if(temp==s) ans=min(ans,d);
		return;
	}
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			if(map[i][j]=='.'){
				map[i][j]='*';
				dfs(cnt+1,d+(abs(coor[cnt].first-i)+abs(coor[cnt].second-j)));
				map[i][j]='.';
			}
		}
	}
}
int main(){
	for(int i=0;i<5;++i) cin>>map[i];
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j) 
			if(map[i][j]=='*'){
				coor.push_back({i,j});
				++s;
				map[i][j]='.';
			}
	dfs(0,0);
	cout<<ans<<'\n';
}
