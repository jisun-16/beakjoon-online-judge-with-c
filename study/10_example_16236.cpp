#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int n, arr[21][21], s_x, s_y;
bool visited[21][21];

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==9){
				s_x=i;
				s_y=j;
			}
		}
	
	int ans=0,size=2,cnt=0;
	arr[s_x][s_y]=0;
	while(1){
		memset(visited,false,sizeof(visited));
		
		priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > pq; 
		pq.push({0,{s_x,s_y}});
		visited[s_x][s_y]=true;
		
		bool eat=false;
		while(!pq.empty()){
			int x=pq.top().second.first,y=pq.top().second.second;
			int time=pq.top().first;
			pq.pop();
			
			if(arr[x][y]>size) continue;
			if(arr[x][y]&&arr[x][y]<size){
				arr[x][y]=0;
				cnt++;
				if(cnt==size){
					size++;
					cnt=0;
				}
				s_x=x;
				s_y=y;
				ans+=time;
				eat=true;
				break;
			}
			
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(nx<0||nx>=n||ny<0||ny>=n) continue;
				if(visited[nx][ny]) continue;
				visited[nx][ny]=true;
				pq.push({time+1,{nx,ny}});
			}
		}
		if(!eat) break;
	}
	
	cout<<ans<<'\n';
}
