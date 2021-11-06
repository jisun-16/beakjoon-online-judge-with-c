#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int n, fish[21][21], fish_cnt[10], size, cnt, ans;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool visited[21][21];

int x,y;//상어의 현재 위치 

int _bfs(){
	memset(visited,false,sizeof(visited));
	queue<pair<int,int> > q;
	
	q.push({x,y});
	
	int time=0;
	while(!q.empty()){
		int temp=q.size();
		while(temp--){
			int u=q.front().first,v=q.front().second;
			
			if(visited[u][v]) continue;
			visited[u][v]=true;
			
			if(fish[u][v]&&fish[u][v]<size){
				memset(visited,false,sizeof(visited));
				fish[u][v]=0;
				visited[u][v]=true;
				fish_cnt[fish[u][v]]--;
				cnt++;
			}
				
			if(size==cnt){
				size++;
				cnt=0;
			}
			
			for(int i=0;i<4;i++){
				int nu=u+dx[i],nv=v+dy[i];
				
				if(nu<0||nu>=n||nv<0||nv>=n) continue;
				if(fish[nu][nv]>=size) continue;
				
				q.push({nu,nv});	
			}
		}
		time++;
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>fish[i][j];
			if(fish[i][j]==9){
				x=i;y=j;
			} 
			else if(fish[i][j]) fish_cnt[fish[i][j]]++;
		}
	}
	
	size=2;
	
	bool avail=false;
	for(int i=1;i<size;i++)
		if(fish_cnt[i]){
			avail=true;
			break;
		}
	
	while(avail){
		ans+=_bfs();
		
		avail=false;
		for(int i=1;i<size;i++)
			if(fish_cnt[i]){
				avail=true;
				break;
			}
	}
	
	cout<<ans<<'\n';
}
