#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>

using namespace std;

int n,arr[101][101];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool visited[101][101];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) cin>>arr[i][j];
		
	int s=0,e=200,ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		
		for(int i=0;i<=200-mid;i++){
			int _min=i,_max=i+mid;
			if(arr[1][1]<_min||arr[1][1]>_max) continue;
			
			memset(visited,false,sizeof(visited));
			
			queue<pair<int,int> > q;
			q.push({1,1});
			visited[1][1]=true;
			while(!q.empty()){
				int x=q.front().first,y=q.front().second;
				q.pop();
				
				for(int d=0;d<4;d++){
					int nx=x+dx[d],ny=y+dy[d];
					if(nx<=0||nx>n||ny<=0||ny>n) continue;
					if(visited[nx][ny]) continue;
					if(_max<arr[nx][ny]||_min>arr[nx][ny]) continue;
					
					visited[nx][ny]=true;
					q.push({nx,ny});
				}
			}
			
			if(visited[n][n]) break;
		}
		
		if(!visited[n][n]) s=mid+1;
		else{
			ans=mid;
			e=mid-1;
		}
	}
	
	cout<<ans<<'\n';
}
