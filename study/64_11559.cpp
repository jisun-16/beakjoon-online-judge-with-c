#include<iostream>
#include<queue>
using namespace std;
char arr[12][6];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int main(){
	for(int i=0;i<12;i++)
		for(int j=0;j<6;++j) cin>>arr[i][j];
	int ans=0;
	while(true){
		bool visited[12][6]={0,};
		bool chk=false;
		for(int i=0;i<12;++i){
			for(int j=0;j<6;++j){
				if(visited[i][j]||arr[i][j]=='.') continue;
				queue<pair<int,int> > q;
				char c=arr[i][j];
				int cnt=0;
				q.push({i,j});
				visited[i][j]=true;
				cnt++;
				while(!q.empty()){
					int x=q.front().first,y=q.front().second;
					q.pop();
					for(int d=0;d<4;++d){
						int nx=x+dx[d],ny=y+dy[d];
						if(nx<0||nx>=12||ny<0||ny>=6||visited[nx][ny]||arr[nx][ny]!=c) continue;
						q.push({nx,ny});
						visited[nx][ny]=true;
						cnt++;
					}
				}
				if(cnt>=4){
					chk=true;
					q.push({i,j});
					arr[i][j]='.';
					while(!q.empty()){
						int x=q.front().first,y=q.front().second;
						q.pop();
						for(int d=0;d<4;++d){
							int nx=x+dx[d],ny=y+dy[d];
							if(nx<0||nx>=12||ny<0||ny>=6||arr[nx][ny]!=c) continue;
							q.push({nx,ny});
							arr[nx][ny]='.';
						}
					}
				}
			}
		}
		if(!chk) break;
		ans++;
		for(int i=11;i>=0;--i)
			for(int j=0;j<6;++j){
				if(arr[i][j]!='.') continue;
				int k=i;
				while(k--){
					if(arr[k][j]!='.'){
						arr[i][j]=arr[k][j];
						arr[k][j]='.';
						break;
					}
				}
			}
	}
	cout<<ans<<'\n';
}
