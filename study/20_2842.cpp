#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n,ex[51][51];
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
char map[51][51];
pair<int,int> s;
bool visited[51][51];
vector<int> v;

int _dfs(int x,int y,int l,int r){
	if(ex[x][y]<v[l]||ex[x][y]>v[r]) return 0;
	
	int ret=0;
	
	if(map[x][y]=='K') ++ret;
	
	for(int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(visited[nx][ny]) continue;
		
		visited[nx][ny]=true;
		ret+=_dfs(nx,ny,l,r);
	}
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]=='P') s={i,j};
			else if(map[i][j]=='K') cnt++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>ex[i][j];
			v.push_back(ex[i][j]);
		} 
	
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	int ans=1e6,l=0,r=0;
	while(l<=r){
		memset(visited,false,sizeof(visited));
		
		int temp=_dfs(s.first,s.second,l,r);
		
		if(temp<cnt&&r+1<v.size()) ++r;
		else if(temp==cnt) {
			ans=min(ans,v[r]-v[l]);
			++l;
		}
		else break;
	}
	
	cout<<ans<<'\n';
}
