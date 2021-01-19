#include<iostream>
#include<algorithm>
#include<vector>
#define pii pair<int,int>

using namespace std;

int n,h,root,hei[10001],par[10001],diff[10001],ans;
vector<pii> adj[10001];
vector<int> des[10001];
bool visited[10001];

void dfs(int now,int idx,int dist){
	visited[now]=true;
	hei[now]=dist;
	des[idx].push_back(now);
	if(adj[now].size()==0) //leaf
		diff[now]=dist-h;
	for(int i=0;i<adj[now].size();++i){
		int next=adj[now][i].first,cost=adj[now][i].second;
		if(visited[next]) continue;
		dfs(next,idx+1,dist+cost);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>h;
	for(int i=1;i<=n;++i){
		int a,b;
		cin>>a>>b;
		if(a==0) root=i;
		else par[i]=a,adj[a].push_back({i,b});//a->i
	}
	
	dfs(root,0,0);
	
	for(int i=n-1;i>=0;--i){
		for(int j=0;j<des[i].size();++j){
			int now=des[i][j];
			if(hei[par[now]]>=diff[now])
				diff[par[now]]=max(diff[now],diff[par[now]]);
			else
				diff[par[now]]=hei[par[now]],ans+=diff[now]-hei[par[now]];
		}
	}
	
	cout<<ans<<'\n';
}
