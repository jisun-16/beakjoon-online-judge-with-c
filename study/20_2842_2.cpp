#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int n;
char arr1[50][50];
int arr2[50][50];

int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

pair<int,int> st;
int k_cnt,v[2500],idx,mn[50][50];
set<int> s;
vector<pair<int,int> > k_coor;
bool visited[50][50];

int _bfs1(int l){
	if(l>arr2[st.first][st.second]) return -1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			visited[i][j]=false;
			mn[i][j]=1e9;
		}
	int u=arr2[st.first][st.second];
	queue<pair<int,int> > q;
	q.push(st);
	mn[st.first][st.second]=u;
	int cnt=0;
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		
		if(arr1[x][y]=='K'&&!visited[x][y]){
			cnt++;
			visited[x][y]=true;
		}
		
		for(int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<0||nx>=n||ny<0||ny>=n) continue;
			if(arr2[nx][ny]<l) continue;
			
			int temp=max(mn[x][y],arr2[nx][ny]);
			if(mn[nx][ny]>temp){
				mn[nx][ny]=temp;
				q.push({nx,ny});
			}
		}
	}
	
	if(cnt<k_cnt) return -1;
	for(auto &iter:k_coor) u=max(u,mn[iter.first][iter.second]);
	
	return u;
}

int _bfs2(int u){
	if(u<arr2[st.first][st.second]) return -1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			visited[i][j]=false;
			mn[i][j]=0;
		}
	
	int l=arr2[st.first][st.second];
	queue<pair<int,int> > q;
	q.push(st);
	mn[st.first][st.second]=l;
	int cnt=0;
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		
		if(arr1[x][y]=='K'&&!visited[x][y]){
			cnt++;
			visited[x][y]=true;
		}
		
		for(int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<0||nx>=n||ny<0||ny>=n) continue;
			if(arr2[nx][ny]>u) continue;
			
			int temp=min(mn[x][y],arr2[nx][ny]);
			if(mn[nx][ny]<temp){
				mn[nx][ny]=temp;
				q.push({nx,ny});
			}
		}
	}
	
	if(cnt<k_cnt) return -1;
	for(auto &iter:k_coor) l=min(l,mn[iter.first][iter.second]);
	
	return l;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>arr1[i][j];
			if(arr1[i][j]=='P') st={i,j};
			else if(arr1[i][j]=='K') {
				++k_cnt;
				k_coor.push_back({i,j});
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>arr2[i][j];
			s.insert(arr2[i][j]);
		}
	
	for(auto iter:s) v[idx++]=iter;
	
	int ans=1e6;
	for(int i=0;i<idx;){
		int u=_bfs1(v[i]);
		if(u==-1) break;
		
		int l=_bfs2(u);
		if(l==-1) break;
		
		ans=min(ans,u-l);
		i=upper_bound(v,v+idx,l)-v;
	}
	
	cout<<ans<<'\n';
}
