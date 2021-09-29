#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N,M,arr[25][25],T,D,ans;
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int dist[2][25][25];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>T>>D;
	for(int i=0;i<N;++i){
		string temp;
		cin>>temp;
		for(int j=0;j<M;++j){
			dist[0][i][j]=-1;
			dist[1][i][j]=-1;
			if(temp[j]>='A'&&temp[j]<='Z')
				arr[i][j]=(temp[j]-'A');
			else
				arr[i][j]=(temp[j]-'a')+26;
		}
	}
	priority_queue<pair<int,pair<int,int> > > pq;
	pq.push({0,{0,0}});
	dist[0][0][0]=0;
	while(!pq.empty()){
		int cost=-pq.top().first;
		int x=pq.top().second.first,y=pq.top().second.second;
		pq.pop();
		for(int i=0;i<4;++i){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M||arr[nx][ny]-arr[x][y]>T||arr[x][y]-arr[nx][ny]>T) continue;
			int nd=arr[x][y]>=arr[nx][ny]?1:(arr[nx][ny]-arr[x][y])*(arr[nx][ny]-arr[x][y]);
			if(dist[0][nx][ny]==-1||dist[0][nx][ny]>cost+nd){
				dist[0][nx][ny]=cost+nd;
				pq.push({-(cost+nd),{nx,ny}});
			}
		}
	}
	pq.push({0,{0,0}});
	dist[1][0][0]=0;
	while(!pq.empty()){
		int cost=-pq.top().first;
		int x=pq.top().second.first,y=pq.top().second.second;
		pq.pop();
		for(int i=0;i<4;++i){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M||arr[nx][ny]-arr[x][y]>T||arr[x][y]-arr[nx][ny]>T) continue;
			int nd=arr[x][y]<=arr[nx][ny]?1:(arr[nx][ny]-arr[x][y])*(arr[nx][ny]-arr[x][y]);
			if(dist[1][nx][ny]==-1||dist[1][nx][ny]>cost+nd){
				dist[1][nx][ny]=cost+nd;
				pq.push({-(cost+nd),{nx,ny}});
			}
		}
	}
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(dist[0][i][j]!=-1&&dist[1][i][j]!=-1&&dist[0][i][j]+dist[1][i][j]<=D)
				ans=max(ans,arr[i][j]);
	cout<<ans<<'\n';
}
