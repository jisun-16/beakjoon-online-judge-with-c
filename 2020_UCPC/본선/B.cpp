#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

const int dx[]={-1,0},dy[]={0,-1};
int n,m,k;
string row[26],map;

bool _avail(int a,int b){
	return a>=0&&a<n&&b>=0&&b<m;
}

int main(){
	
	cin>>n>>m>>k;
	for(int i=0;i<k;i++) cin>>row[i];
	cin>>map;

	int ans=1;
	queue<pair<int,int> > q;
	q.push({n-1,m-1});
	while(!q.empty()){
		int temp=q.size();
		bool visited[m]={false,};
		
		while(temp--){
			int x=q.front().first,y=q.front().second;
			q.pop();
			
			for(int i=0;i<2;i++){
				int nx=x+dx[i],ny=y+dy[i];
				
				if(!_avail(nx,ny)) continue;
				if(visited[ny]) continue;
				
				if(i==0&&row[map[nx]-'A'][ny]=='U'){
					ans++;
					visited[ny]=true;
					q.push({nx,ny});
				}
				if(i==1&&row[map[nx]-'A'][ny]=='R'){
					ans++;
					visited[ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
	
	cout<<ans<<'\n';
}
