#include<iostream>
#include<queue>
using namespace std;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int w,h,ans,cnt,dist[11][11]={0,};
char arr[20][20];
bool chked[11];
pair<int,int> dirty[11];

void dfs(int now,int chk,int td){
	if(chk==cnt){
		ans=ans<td?ans:td;
		return;
	}
	for(int i=1;i<=cnt;++i){
		if(chked[i]) continue;
		chked[i]=true;
		if(dist[now][i]!=-1)
			dfs(i,chk+1,td+dist[now][i]);
		chked[i]=false;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(true){
		ans=987654321,cnt=0;
		for(int i=0;i<11;++i) {
			chked[i]=false;
			for(int j=0;j<11;++j) dist[i][j]=0;
		}
		
		cin>>w>>h;
		if(w==0&&h==0) break;
		for(int i=0;i<h;++i){
			cin>>arr[i];
			for(int j=0;j<w;++j)
				if(arr[i][j]=='o') dirty[0]={i,j};
				else if(arr[i][j]=='*') dirty[++cnt]={i,j};
		}
		
		for(int i=0;i<=cnt;++i)
			for(int j=i+1;j<=cnt;++j){
				queue<pair<int,int> > q;
				bool visited[20][20]={0,};
				int dd=0;
				q.push(dirty[i]);
				visited[dirty[i].first][dirty[i].second]=true;
				while(!q.empty()&&!dist[i][j]){
					int temp=q.size();
					while(temp--&&!dist[i][j]){
						int x=q.front().first,y=q.front().second;
						q.pop();
						if(x==dirty[j].first&&y==dirty[j].second){
							dist[i][j]=dd;
							break;
						}
						for(int d=0;d<4;++d){
							int nx=x+dx[d],ny=y+dy[d];
							if(nx<0||nx>=h||ny<0||ny>=w||arr[nx][ny]=='x'||visited[nx][ny]) continue;
							visited[nx][ny]=true;
							q.push({nx,ny});
						}
					}
					++dd;
				}
				if(!dist[i][j]) dist[i][j]=-1;
				dist[j][i]=dist[i][j];
			}
		
		dfs(0,0,0);
		cout<<(ans==987654321?-1:ans)<<'\n';
	}
}
