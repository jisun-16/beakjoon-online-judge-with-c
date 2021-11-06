#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,s,e,ans;
int dist[10001];//끝에서 역순으로 누적 
bool visited[10001];
vector<pair<int,int> > graph[10001];

void _dfs(int now){
	for(int i=0;i<graph[now].size();i++){
		int next=graph[now][i].first;
		int wei=graph[now][i].second;
		
		if(!dist[next]) _dfs(next);
		dist[now]=max(dist[now],dist[next]+wei);
	}
}

void _tracking(int now){
	if(visited[now]) return;
	visited[now]=true;
	for(int i=0;i<graph[now].size();i++){
		int next=graph[now][i].first;
		int wei=graph[now][i].second;
		if(dist[next]+wei==dist[now]){
			ans++;
			_tracking(next);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
	}
	cin>>s>>e;
	
	_dfs(s);
	_tracking(s);
	
	cout<<dist[s]<<'\n';
	cout<<ans<<'\n';
}
