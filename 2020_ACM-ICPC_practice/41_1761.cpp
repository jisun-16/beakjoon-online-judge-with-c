/*LCA알고리즘 : https://jason9319.tistory.com/110 참고*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,par[40001][20],dep[40001],dist[40001];
vector<pair<int,int> > adj[40001];
bool visited[40001];
void dfs(int u,int dp,int dt){
	visited[u]=true;
	dep[u]=dp;
	dist[u]=dt;
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i].first,t=adj[u][i].second;
		if(!visited[v]){
			dfs(v,dp+1,dt+t);
			par[v][0]=u;
		}
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=19;i>=0;--i)
		if(dep[y]-dep[x]>=(1<<i)) y=par[y][i];
	if(x==y) return x;
	for(int i=19;i>=0;--i)
		if(par[x][i]!=par[y][i])
			x=par[x][i],y=par[y][i];
	return par[x][0];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	dfs(1,0,0);
	for(int i=1;i<20;++i){
		for(int j=1;j<=n;++j)
			par[j][i]=par[par[j][i-1]][i-1];
	}
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		int idx=lca(x,y);
		cout<<dist[x]+dist[y]-2*dist[idx]<<'\n';
	}
}
